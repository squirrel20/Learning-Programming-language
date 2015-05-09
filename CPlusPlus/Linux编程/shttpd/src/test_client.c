
/*
 *  客户端测试代码，用于UNP中的代码测试，和shttpd无关
 */

#include "func.h"

void
str_cli(FILE *fp, int sockfd)
{
	int 	maxfdp1, stdineof, n;
	char	sendline[MAX_SIZE], recvline[MAX_SIZE];
	fd_set	rset;

	stdineof = 0;
	FD_ZERO(&rset);

	while(1) {
		if(stdineof == 0)
			FD_SET(fileno(fp), &rset)
		FD_SET(sockfd, &rset);
		maxfdp1 = max(fileno(fp), sockfd) + 1;
		Select(maxfdp1, &rset, NULL, NULL, NULL);

		if (FD_ISSET(sockfd, &rset)) {
			if(Readline(sockfd, recvline, MAX_SIZE) == 0) {
				if (stdineof == 1)
					return;
				else
					err_sys("str_cli: server terminated prematurely");
			}
				
			Write(fileno(stdout), buf, n);
		}

		if (FD_ISSET(fileno(fp), &rset)) {
			if ((n = Read(fileno(fp), buf, MAX_SIZE)) == 0) {
				stdineof = 1;
				Shutdown(sockfd, SHUT_WR);
				FD_CLR(fileno(fp), &rset);
				continue;
			}

			Write(sockfd, buf, n);
		}
	}
}

int
main(int argc, char **argv)
{
	int						sockfd;
	struct sockaddr_in		servaddr;

	if (argc != 2)
		err_sys("usage: test_client <IPaddress>");

	sockfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	Connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	
	str_cli(stdin, sockfd)	;

	exit(0);
}