#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

ssize_t write_fd(int, void *, size_t, int);

int
main(int argc, char **argv)
{
	int fd;

	if (argc != 4) {
		fprintf(stderr, "openfile <sockfd#> <filename> <mode>");
		exit(1);
	}

	if ( (fd = open(argv[2], atoi(argv[3]))) < 0)
		exit( (errno > 0) ? errno : 255 );

	if (write_fd(atoi(argv[1]), " ", 1, fd) < 0)
		exit( (errno > 0) ? errno : 255 );

	exit(0);
}

ssize_t
write_fd(int fd, void *ptr, size_t nbytes, int sendfd)
{
	struct msghdr 	msg;
	struct iovec	iov[1];

	union {
		struct cmsghdr 	cm;
		char 			control[CMSG_SPACE(sizeof(int))];
	} control_un;
	struct cmsghdr 	*cmptr;

	msg.msg_control = control_un.control;
	msg.msg_controllen = sizeof(control_un.control);
	cmptr = CMSG_FIRSTHDR(&msg);
	cmptr->cmsg_len = CMSG_LEN(sizeof(int));
	cmptr->cmsg_level = SOL_SOCKET;
	cmptr->cmsg_type = SCM_RIGHTS;
	*((int *) CMSG_DATA(cmptr)) = sendfd;

	msg.msg_name = NULL;
	msg.msg_namelen = 0;

	iov[0].iov_base = ptr;
	iov[0].iov_len = nbytes;
	msg.msg_iov = iov;
	msg.msg_iovlen = 1;

	return(sendmsg(fd, &msg, 0));
}
