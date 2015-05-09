
#ifndef FUNC_H_
#define FUNC_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <errno.h>

#define MAX_SIZE 1024
#define OPEN_MAX 512
#define PORT 8000
#define CONFIG_PATH \
    "/home/squirrel20/Dropbox/Projects/mini_nginx/server/httpd.conf"

int     _port;
char   *_name_server;

int     Socket(int, int, int);
int     Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int 	Fork();
int     Select(int maxfdp1, fd_set *readset, fd_set *writeset, 
            fd_set *exceptset, const struct timeval *timeout);
int     max(int a, int b);
void    Listen(int sockfd, int backlog);
void    Close(int fd);
void    Bind(int sockfd, const struct sockaddr *addr,
                socklen_t addrlen);
void    Fputs(const char *s, FILE *stream);
void 	Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
void	Inet_pton(int af, const char *src, void *dst);
void    Shutdown(int sockfd, int howto);
ssize_t Write(int fd, const void *buf, size_t count);
ssize_t readn(int fd, void *vptr, size_t n);
ssize_t writen(int fd, const void *vptr, size_t n);
ssize_t Writen(int fd, const void *vptr, size_t n);
ssize_t readline(int fd, void *vptr, size_t maxlen);
ssize_t Readline(int fd, void *vptr, size_t maxlen);
ssize_t Read(int fd, void *buf, size_t count);
FILE   *Fopen(const char *path, const char *mode);
char   *Fgets(char *s, int size, FILE *stream);

/* 为了简化函数参数中申明函数，定义函数类型Sigfun */
typedef void Sigfunc(int);
Sigfunc *signal(int signo, Sigfunc *func);

void sig_chld(int signo);

void err_sys(char *err_info);

#endif // FUNC_H_
