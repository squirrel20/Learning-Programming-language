// 多人聊天室

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT "9034"

void *get_in_addr(struct sockaddr *sa)
{
    if (AF_INET == sa->sa_family)
        return &(((struct sockaddr_in *)sa)->sin_addr);

    return &(((struct sockaddr_in6 *)sa)->sin6_addr);
}

int getListener()
{
    struct addrinfo hints, *ai, *p;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int iRet = getaddrinfo(NULL, PORT, &hints, &ai);
    if(0 != iRet) {
        fprintf(stderr, "selectserver: %s\n", gai_strerror(iRet));
        exit(EXIT_FAILURE);
    }

    int iListener;
    int y = 1;
    for(p = ai; NULL != p; p = p->ai_next) {
        iListener = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (iListener < 0) continue;

        // 避开这个错误信息：address already in use
        setsockopt(iListener, SOL_SOCKET, SO_REUSEADDR, &y, sizeof(int));

        if (bind(iListener, p->ai_addr, p->ai_addrlen) < 0) {
            close(iListener);
            continue;
        }

        break;
    }

    if (NULL == p) {
        fprintf(stderr, "selectserver: failed to bind\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(ai);

    if(listen(iListener, 10) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    return iListener;
}

int main(void)
{
    int iListener = getListener();
    printf("listening...\n");

    fd_set master;
    fd_set read_fds;

    FD_SET(iListener, &master);
    int fdmax = iListener;

    for(;;) {
        read_fds = master;

        // 阻塞在这里，等待可以读的连接
        if(select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        for(int i = 0; i <= fdmax; i++) {
            if(!(FD_ISSET(i, &read_fds))) continue;

            if(i == iListener) {
                // 来了一个新连接
                struct sockaddr_storage stRemoteAddr;
                socklen_t iAddrLen = sizeof stRemoteAddr;
                int iNewFd = accept(iListener, 
                        (struct sockaddr *)&stRemoteAddr, &iAddrLen);

                if(-1 == iNewFd) {
                    perror("accept");
                } else {
                    FD_SET(iNewFd, &master);
                    if(iNewFd > fdmax) {
                        fdmax = iNewFd;
                    }
                    char remoteIp[INET6_ADDRSTRLEN];
                    printf("selectserver: new connection from %s on "
                            "socket %d\n",
                            inet_ntop(stRemoteAddr.ss_family,
                                get_in_addr((struct sockaddr*)&stRemoteAddr),
                                remoteIp, INET6_ADDRSTRLEN),
                            iNewFd);
                }
            } else {
                char buf[256];
                int iRet = recv(i, buf, sizeof buf, 0);
                if(iRet <= 0) {
                    if(0 == iRet) {
                        printf("selectserver: socket %d hung up\n", i);
                    } else {
                        perror("recv");
                    }

                    close(i);
                    FD_CLR(i, &master);
                } else {
                    for(int j = 0; j <= fdmax; j++) {
                        if(!(FD_ISSET(j, &master))) continue;
                        if(j == iListener || j == i) continue;

                        if(send(j, buf, iRet, 0) == -1) perror("send");
                    }
                }
            }
        }
    }
    return 0;
}
