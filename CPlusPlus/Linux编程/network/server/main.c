/*
 * Created on: Jul 22, 2013
 * Author: Liao Song
 * e-mail: ls200853#gmail.com
 *
 */

#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SERV_PORT 8888;

int
main(int argc, char **argv)
{
	int		listenfd, connfd;
	pid_t	childpid;
	socklen_t	clilen;
	struct sockaddr_in cliaddr, servaddr;	// Just work for IPv4
	
	// Listen
	if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		puts("socket error!");
		exit(1);
	}
	/*
	// Init server address
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);

	// Bind
	if(bind(listenfd, &servaddr, sizeof(servaddr)) == -1)
	{
		puts("bind error");
		exit(1);
	}

	// Listen
	if(listen(listenfd, LISTENQ) == -1)
	{
		puts("listen error");
		exit(1);
	}

	for(;;){
		clilen = sizeof(cliaddr);
		// Accept
		if((connfd = accept(listenfd, &cliaddr, &clilen)) == -1){
			puts("accept error");
			exit(1);
		}

		// Fork
		childpid = fork();
		if(childpid  == -1){
			puts("fork error");
			exit(1);
		}else if(childpid == 0){
			close(listenfd);
			// do something
			exit(0);
		}

		close(connfd);
	}
	*/
}
