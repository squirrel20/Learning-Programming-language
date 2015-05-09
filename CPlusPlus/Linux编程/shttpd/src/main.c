
/*
 * A sample server!
 * 2013/12/25 21:19
 */

#include <poll.h>
#include <sys/stropts.h>
#include <string.h>
#include <limits.h>

#include "func.h"
#include "main.h"

/*
 * POSIX规范要求在头文件<poll.h>中定义INFTIM，不过许多系统仍然把它定义在头文件<sys/stropts
 * .h>中。不过在我的 Ubuntu 12.04.2 LTS 64位系统中这两个头文件中都没有定义INFTIM。
 */
#ifndef INFTIM
#define INFTIM -1
#endif

int 
main(int argc, char *argv[])
{
    return test_server_fork(argc, argv);
}

int
server(int argc, char **argv)
{
    int     server_sockfd, client_sockfd, server_len, client_len;
    struct  sockaddr_in server_address, client_address;

    get_conf();

    server_sockfd = Socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    /* server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); */
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);
    server_len = sizeof(server_address);
    Bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

    Listen(server_sockfd, 5);

    /*
     * 在服务器子进程终止时，给父进程发送一个SIGCHILD信号。该信号的默认行为是被忽略，如果父进
     * 程未加处理，子进程就会进入僵死状态，状态码为‘z’，使用ps命令可以查看：
     * ps -t pts/6 -o pid,ppid,tty,stat,args,wchan
     * signal函数的第一个参数是信号名，第二个参数或为指向函数的指针，或为常值SIG_IGN或
     * SIG_DFL。也可以使用遵循POSIX标准的函数：sigaction
     */

    signal(SIGCHLD, sig_chld);


    while (1) {
        printf("server waiting\n");
        client_len = sizeof(client_address);
        if ((client_sockfd = accept(server_sockfd,
            (struct sockaddr *)&client_address, &client_len)) < 0) {

            /*
             * 处理由SIGCHLD信号中断的系统调用。
             * 当子进程终止发送SIGCHLD信号，会产生信号中断，这种情况应该恢复accept系统调
             * 用。
             * [Unix网络编程 卷一 第3版][P107]
             *
             * 发生错误标志ECONNABORTED的情况：
             * 当三次握手完成从而建立连接后，客户TCP却发送了一个RST（复位）。在服务器端看来，
             * 就在该连接已有TCP排队，等着服务器进程调用accept的时候RST到达。稍后，服务器进
             * 程调用accept。
             * [Unix网络变成 卷一 第3版][P111]
             */

            if ( errno == EINTR || errno == ECONNABORTED ) 
                continue;
            else 
                err_sys("accept error");
            
        }
        if (Fork() == 0) {
            Close(server_sockfd);
            handle(client_sockfd);
            Close(client_sockfd);
            exit(0);

        } 

        Close(client_sockfd);
    }

    return 0;
}

void 
handle(int client_sockfd)
{
    char readBuf[MAX_SIZE];
    char out[] = 
        "HTTP/1.0 200 OK\r\n\r\n<html><head></head><body>hi</body></html>";
    read(client_sockfd, readBuf, MAX_SIZE);
    write(client_sockfd, out, strlen(out));
}

int
test_server_fork(int argc, char **argv)
{
    int                 listenfd, connfd;
    pid_t               childpid;
    socklen_t           clilen;
    struct sockaddr_in  cliaddr, servaddr;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    Listen(listenfd, 5);

    for (; ; ) {
        clilen = sizeof(cliaddr);
        if( (connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen)) <
            0) {
            if(errno == EINTR)
                continue;
            else
                err_sys("accept error");
        }
        if( (childpid = Fork()) == 0) {
            Close(listenfd);
            str_echo(connfd);
            exit(0);
        }

        Close(connfd);

    }

    return 0;
}
int
test_server_select(int argc, char **argv)
{
    int 					i, maxi, maxfd, listenfd, connfd, sockfd, nready,
    						client[FD_SETSIZE];
    char					buf[MAX_SIZE];
    fd_set					rset, allset;
    ssize_t					n;
    socklen_t				clilen;
    struct sockaddr_in		cliaddr, servaddr;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    Listen(listenfd, 5);

    maxfd = listenfd;
    maxi = -1;
    for (i = 0; i < FD_SETSIZE; i++)
    	client[i] = -1;
    FD_ZERO(&allset);
    FD_SET(listenfd, &allset);

    while (1) {
    	rset = allset;
    	/*
    	 * 阻塞于select调用
    	 */
    	nready = Select(maxfd + 1, &rset, NULL, NULL, NULL);

    	if (FD_ISSET(listenfd, &rset)) {
    		clilen = sizeof(cliaddr);
    		connfd = Accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);

    		for (i = 0; i < FD_SETSIZE; i++)
    			if (client[i] < 0) {
    				client[i] = connfd;
    				break;
    			}
    		if (i == FD_SETSIZE)
    			err_sys("too many clients");

    		FD_SET(connfd, &allset);
    		if(connfd > maxfd)
    			maxfd = connfd;
    		if(i > maxi)
    			maxi = i;

    		if(--nready <= 0)
    			continue;
    	}

    	for (i = 0; i < maxi; i++) {
    		if ( (sockfd = client[i]) < 0)
    			continue;
    		if (FD_ISSET(sockfd, &rset)) {
    			/*
    			 * 此处不应该阻塞于单个客户端的read调用，这样容易受到拒绝服务型攻击
    			 */
    			if ( (n = Read(sockfd, buf, MAX_SIZE)) == 0) {
    				/*
    				 * 套接字关闭时
    				 */
    				Close(sockfd);
    				FD_CLR(sockfd, &allset);
    				client[i] = -1;
    			} else
    				Writen(sockfd, buf, n);
    		}

    		if (--nready <= 0)
    			break;
    	}
    }

    return 0;
}

int
test_server_poll(int argc, char **argv)
{
	int 				i, maxi, listenfd, connfd, sockfd, nready;
	char 				buf[MAX_SIZE];
	ssize_t 			n;
	socklen_t 			clilen;
	struct pollfd 		client[OPEN_MAX];
	struct sockaddr_in 	cliaddr, servaddr;

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	Listen(listenfd, 5);

	client[0].fd 		= listenfd;
	client[0].events	= POLLRDNORM;
	for (i = 1; i < OPEN_MAX; i++)
		client[i].fd = -1;
	maxi = 0;

	while (1) {
		nready = Poll(client, maxi + 1, INFTIM);

		if (client[0].revents & POLLRDNORM) {
			clilen = sizeof(cliaddr);
			connfd = Accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);

			for (i = 1; i < OPEN_MAX; i++)
				if (client[i].fd < 0) {
					client[i].fd = connfd;
					break;
				}
			if (i == OPEN_MAX)
				err_sys("too many clients");

			client[i].events = POLLRDNORM;
			if (i > maxi)
				maxi = i;

			if (--nready <= 0)
				continue;
		}

		for (i = 1; i <= maxi; i++) {
			if ( (sockfd = client[i].fd) < 0)
				continue;
			if (client[i].revents & (POLLRDNORM | POLLERR)) {
				if ( (n = read(sockfd, buf, MAX_SIZE)) < 0) {
					if (errno == ECONNRESET) {
						Close(sockfd);
						client[i].fd = -1;

					} else
						err_sys("read error");
				} else if (n == 0) {
					Close(sockfd);
					client[i].fd = -1;
				} else
					Writen(sockfd, buf, n);

				if (--nready <= 0)
					break;
			}
		}
	}

	return 0;
}

void
str_echo(int sockfd)
{
    char        buf[MAX_SIZE];
    ssize_t     n;

again:
    while ( (n = read(sockfd, buf, MAX_SIZE)) > 0)
        Write(sockfd, buf, n);

    if(n < 0 && errno == EINTR)
        goto again;
    else if (n < 0)
        err_sys("str_echo: read error");
}
