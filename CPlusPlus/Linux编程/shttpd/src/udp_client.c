#include "func.h"

void
dg_cli(FILE *, int , const struct sockaddr *, socklen_t);

int
main(int argc, char **argv)
{
	int 					sockfd;
	struct sockaddr_in 		servaddr;

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	Inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

	sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

	dg_cli(stdin, sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	return 0;
}

void
dg_cli(FILE *fp, int sockfd, const struct sockaddr *pservaddr, socklen_t
		servlen)
{
	int 	n;
	char	sendline[MAX_SIZE], recvline[MAX_SIZE];

	while (Fgets(sendline, MAX_SIZE, fp) != NULL) {

		sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);

		/*
		 * 如果sendto发出去的数据报丢失了，那么recvfrom将一直阻塞，一种解决方法是设置超时
		 */
		n = recvfrom(sockfd, recvline, MAX_SIZE, 0, NULL, NULL);

		recvline[n] = 0;
		Fputs(recvline, stdout);
	}
}
