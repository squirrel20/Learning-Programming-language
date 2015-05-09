#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/un.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFSIZE 1024

int 	my_open(const char *, int);
ssize_t read_fd(int, void *, size_t, int *);

int
main(int argc, char **argv)
{
	int 	fd, n;
	char 	buff[BUFFSIZE];

	if (argc != 2) {
		fprintf(stderr, "usage: mycat <pathname>\n");
		exit(1);
	}

	if ( (fd = my_open(argv[1], O_RDONLY)) < 0 ) {
		fprintf(stderr, "cannot open %s\n", argv[1]);
		exit(1);
	}

	while ( (n = read(fd, buff, BUFFSIZE)) > 0 )
		write (STDOUT_FILENO, buff, n);

	exit(0);
}

int
my_open(const char *pathname, int mode)
{
	int 	fd, status, sockfd[2];
	char 	c, argsockfd[10], argmode[10];
	pid_t	childpid;

	socketpair(AF_LOCAL, SOCK_STREAM, 0, sockfd);

	if ( (childpid = fork()) == 0) {
		/* child process */
		close(sockfd[0]);
		snprintf(argsockfd, sizeof(argsockfd), "%d", sockfd[1]);
		snprintf(argmode, sizeof(argmode), "%d", mode);
		execl("./openfile", "openfile", argsockfd, pathname, argmode, (char*)NULL);
		fprintf(stderr, "execl error");
		exit(1);
	}

	/* parent process - wait fo the child to terminate */
	close(sockfd[1]);
	waitpid(childpid, &status, 0);
	if (WIFEXITED(status) == 0) {
		fprintf(stderr, "child not terminate\n");
		exit(1);
	}
	if ( (status = WEXITSTATUS(status)) == 0 )
		read_fd(sockfd[0], &c, 1, &fd);
	else {
		errno = status;
		fd = -1;
	}
	close(sockfd[0]);

	return(fd);
}

ssize_t
read_fd(int fd, void *ptr, size_t nbytes, int *recvfd)
{
	ssize_t 		n;
	struct iovec	iov[1];
	struct msghdr	msg;

	union {
		struct cmsghdr	cm;
		char 			control[CMSG_SPACE(sizeof(int))];
	} control_un;
	struct cmsghdr *cmptr;

	msg.msg_control = control_un.control;
	msg.msg_controllen = sizeof(control_un.control);

	msg.msg_name = NULL;
	msg.msg_namelen = 0;

	iov[0].iov_base = ptr;
	iov[0].iov_len = nbytes;
	msg.msg_iov = iov;
	msg.msg_iovlen = 1;

	if ( (n = recvmsg(fd, &msg, 0)) <= 0 )
		return(n);

	if ( (cmptr = CMSG_FIRSTHDR(&msg)) != NULL &&
			cmptr->cmsg_len == CMSG_LEN(sizeof(int))) {
		if (cmptr->cmsg_level != SOL_SOCKET) {
			fprintf(stderr, "control level != SOL_SOCKET\n");
			exit(1);
		}
		if (cmptr->cmsg_type != SCM_RIGHTS) {
			fprintf(stderr, "control type != STDOUT_RIGHTS\n");
			exit(1);
		}
		*recvfd = *((int *)CMSG_DATA(cmptr));
	} else
		*recvfd = -1;

	return(n);
}
