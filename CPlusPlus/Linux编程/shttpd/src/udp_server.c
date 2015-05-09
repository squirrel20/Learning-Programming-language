#include "func.h"

void dg_echo(int sockfd, struct sockaddr *pcliaddr, socklen_t clilen);

int
main(int argc, char **argv)
{
	int 					sockfd;
	struct sockaddr_in		servaddr, cliaddr;

	sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family 		= AF_INET;
	servaddr.sin_addr.s_addr 	= htonl(INADDR_ANY);
	servaddr.sin_port 			= htons(PORT);

	Bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	return 0;
}

void
dg_echo(int sockfd, struct sockaddr *pcliaddr, socklen_t clilen)
{
	int 		n;
	char		mesg[MAX_SIZE];
	socklen_t	len;

	while (1) {
		len = clilen;
		n = recvfrom(sockfd, mesg, MAX_SIZE, 0, pcliaddr, &len);

		sendto(sockfd, mesg, n, 0, pcliaddr, len);
	}

	socklen_t	len;

}
