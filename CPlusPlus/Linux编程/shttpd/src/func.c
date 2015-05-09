
/*
 * 常用函数
 * 最后更新： 2014-04-27
 */
 
 
#include "func.h"

void
err_sys(char *err_info)
{
    perror(err_info);
    exit(1);
}

int
Socket(int domain, int type, int protocol)
{
    int fd ;

    if( (fd = socket(domain, type, protocol)) == -1)
        err_sys("socket error");

    return fd;
}

void
Bind(int sockfd, const struct sockaddr *addr,
                socklen_t addrlen)
{
    if(bind(sockfd, addr, addrlen) == -1)
        err_sys("bind error");
}

void
Listen(int sockfd, int backlog)
{
    if(listen(sockfd, backlog) == -1)
        err_sys("listen error");
}

int
Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    int fd;
    if((fd = accept(sockfd, addr, addrlen)) == -1)
        err_sys("accept error");
    
    return fd;
}

void
Close(int fd)
{
    if(close(fd) == -1)
        err_sys("close error");
}

ssize_t
Write(int fd, const void *buf, size_t count)
{
    ssize_t n;

    if( (n = write(fd, buf, count)) == -1) 
        err_sys("write error");

    return n;
}

FILE *
Fopen(const char *path, const char *mode)
{
    FILE *file;

    if( (file = fopen(path, mode)) == NULL)
        err_sys("fopen error");
    
    return file;
}

Sigfunc *
signal(int signo, Sigfunc *func)
{
    struct sigaction act, oact;

    act.sa_handler = func;
    
    /*
     * POSIX允许我们能指定这样一组信号，它们在信号处理函数被调用时阻塞。任何阻塞的信号都不能
     * 提交给进程。我们把sa_mask成员设置为空集，意味着在该信号处理函数运行期间，不阻塞额外的
     * 信号。POSIX保证被捕获的信号在其信号处理函数运行期间总是阻塞的。
     * [Unix网络编程：卷1 第3版 P105]
     */
     
    sigemptyset(&act.sa_mask);

    /*
     * SA_RESTART标志是可选的。如果设置，由相应信号中断的系统调用将由内核自动重启。如果被捕
     * 获的信号不是SIGALRM且SA_RESTART有定义，我们就设置该标志。（对SIGALRM进行特殊处理的
     * 原因在于通常是未I/O操作设置潮湿，这种情况下我们希望受阻塞的系统调用被该信号中断掉。）一
     * 些较早期的系统（如SunOS 4.x）默认设置成自动重启被中断的系统调用，并定义了与
     * SA_RESTART互补的SA_INTERRUPT标志。如果定义了该标志，我们就在被捕获的信号是SIGALRM
     * 时设置它。
     * [Unix网络编程：卷1 第3版 P105]
     */
     
    act.sa_flags = 0;
    
    if (signo == SIGALRM) {
#ifdef SA_INTERRUPT
        act.sa_flags |= SA_INTERRUPT;   /* SunOS 4.x */
#endif

    } else {
#ifdef SA_RESTART
        act.sa_flags |= SA_RESTART;     /* SVR4, 4.4BSD */
#endif
    }

    if (sigaction(signo, &act, &oact) < 0) {
        return(SIG_ERR);
    }
    
    return(oact.sa_handler);
}

/* 
 * 子进程退出发送SIGCHLD信号的处理函数
 */
void
sig_chld(int signo)
{
    int     stat;
    pid_t   pid;

    /*
     * 建立一个信号处理函数并在其中调用wait并不足以防止出现僵死进程，当同时由多个SIGCHLD信号
     * 都在信号处理函数执行之前产生，而信号处理函数只会执行一次，因为Unix信号一般是不排队的，
     * 此时，信号处理函数执行完一次后，只会处理掉一个子进程，其余发送了SIGCHLD信号的子进程就
     * 成了僵死进程。
     * 正确的解决办法是调用waitpid而不是wait，我们用一个循环内调用waitpid，以获取所有已终止
     * 子进程的状态。我们必须制定WNOHANG选项，它告知waitpid在由尚未终止的子进程在运行时不要
     * 阻塞。当由终止的子进程时，它就会等待第一个终止的子进程（waitpid第一个参数为‘-1’时），
     * 如此循环当没有终止的子进程后，因为由参数选项WNOHANG，故不阻塞而直接退出循环。参数stat
     * 保存进程终止状态：终止状态、资源利用信息（CPU时间、内存使用量等）
     */
     
    while((pid = waitpid(-1, &stat, WNOHANG)) > 0) {
        printf("child %d terminated\n", pid);
    }

    return;
}

int
Fork()
{
    int pid = fork();

    if(pid < 0) 
        err_sys("fork error");
    
    return pid;
}

void
Inet_pton(int af, const char *src, void *dst)
{
    int ret = inet_pton(af, src, dst);

    if(ret == -1)
        err_sys("af does not contain a valid address family");
    else if (ret == 0)
        err_sys("src does not contain a character string representing a valid "
            " network address in the specified address family");
}

void
Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    if(connect(sockfd, addr, addrlen) == -1)
        err_sys("connect error");
}


/*
 * 从一个描述符中读n个字节
 * 返回实际读了多少字节，若出错返回-1
 */

ssize_t
readn(int fd, void *vptr, size_t n)
{
    char       *ptr;
    size_t      nleft;
    ssize_t     nread;

    ptr = vptr;
    nleft = n;
    while(nleft > 0) {
        if ( (nread = read(fd, ptr, nleft)) < 0) {
            if(errno == EINTR)
                nread = 0;
            else
                return -1;
        } else if (nread == 0)
            break;

        nleft   -= nread;
        ptr     += nread;
    }

    return(n - nleft);
}

/*
 * 往一个描述符写n个字节
 * 若成功则返回n，否则返回-1
 */
ssize_t
writen(int fd, const void *vptr, size_t n)
{
    size_t      nleft;
    ssize_t     nwritten;
    const char *ptr;

    ptr = vptr;
    nleft = n;
    while (nleft > 0) {
        if ( (nwritten = write(fd, ptr, nleft)) <= 0) {
            if (nwritten < 0 && errno == EINTR)
                nwritten = 0;
            else
                return -1;
        }

        nleft   -= nwritten;
        ptr     += nwritten;
    } 

    return n;
}

ssize_t
Writen(int fd, const void *vptr, size_t n)
{
    ssize_t len;

    if((len = writen(fd, vptr, n)) == -1)
        err_sys("writen error");

    return len;
}

/*
 * 从一个描述符读取一行，一次一个字节。效率很低
 */
ssize_t
readline(int fd, void *vptr, size_t maxlen)
{
    char    c, *ptr;
    size_t  n, rc;

    ptr = vptr;
    for(n = 1; n < maxlen; n++) {
    again:
        if ( (rc = read(fd, &c, 1)) == 1) {
            *ptr++ = c;
            if (c == '\n')
                break;
        } else if (rc == 0) {
            *ptr = 0;
            return(n-1);
        } else {
            if (errno == EINTR)
                goto again;
            return -1;
        }
    }

    *ptr = 0;
    return n;
}

ssize_t
Readline(int fd, void *vptr, size_t maxlen)
{
    ssize_t len;

    if((len = readline(fd, vptr, maxlen)) == -1)
        err_sys("readline error");

    return len;
}

int     
Select(int maxfdp1, fd_set *readset, fd_set *writeset, 
            fd_set *exceptset, const struct timeval *timeout)
{
    int num;

    if((num = select(maxfdp1, readset, writeset, exceptset, timeout)) == -1)
        err_sys("select error");

    return num;
}

int
max(int a, int b)
{
    return a > b ? a : b;
}

void
Fputs(const char *s, FILE *stream)
{
    if(fputs(s, stream) == EOF)
        err_sys("fputs error");
}

char*
Fgets(char *s, int size, FILE *stream)
{
	return fgets(s, size, stream);
}

ssize_t
Read(int fd, void *buf, size_t count)
{
    ssize_t len;

    if((len = read(fd, buf, count)) == -1)
        err_sys("read error");

    return len;
}

void
Shutdown(int sockfd, int howto)
{
    if(shutdown(sockfd, howto) == -1)
        err_sys("shutdown error");
}
