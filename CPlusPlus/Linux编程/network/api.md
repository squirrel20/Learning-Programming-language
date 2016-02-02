## 1 struct

```
// AI_PASSIVE   任意IP
// AF_UNSPEC    不管是IPv4或IPv6
// SOCK_STREAM  TCP
// SOCK_DGRAM   UDP
struct addrinfo {
    int ai_flags;               // AI_PASSSIVE, AI_CANONNAME
    int ai_family;              // AF_INET, AF_INET6, AF_UNSPEC
    int ai_socktype;            // SOCK_STREAM, SOCK_DGRAM
    int ai_protocol;            // 0 -> any
    size_t ai_addrlen;          // len -> ai_addr
    struct sockaddr *ai_addr    // struct sockaddr_in or struct sockaddr_in6
    char *ai_canonname;         // hostname
    struct addrinfo *ai_next;
};

struct sockaddr {
    unsigned short sa_family;
    char sa_data[14];
};

struct sockaddr_in {
    short int sin_family;           // AF_INET
    unsigned short int sin_port;    // port number, 2 bytes
    struct in_addr sin_addr;        // internet address, 4 bytes
    unsigned char sin_zero[8];      // 
};

struct in_addr {
    uint32_t s_addr;                // 4 bytes
};

struct sockaddr_in6 {
    u_int16_t sin6_family;          // AF_INET6
    u_int16_t sin6_port;            // port number
    u_int32_t sin6_flowinfo;
    struct in6_addr sin6_addr;      // IPv6 address, 16 bytes
    u_int32_t sin6_scope_id;
};

struct in6_addr {
    unsigned char s6_addr[16];      // IPv6 address, 16 bytes
};

struct sockaddr_storage {
    sa_family_t ss_family;
    char __ss_pad1[_SS_PAD1SIZE];
    int64_t __ss_align;
    char __ss_pad2[_SS_PAD2SIZE];
};
```

## 2 interface

```
// IPv4(IPv6)的网络地址和文本转换
#include <arpa/inet.h>
int inet_pton(int af, const char *src, void *dst);
const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);
```

## 2.1 getaddrinfo

getaddrinfo, freeaddrinfo, gai_strerror - network address and service translation.

```
#include <netdb.h>
ing getaddrinfo(const char * node,              // www.oa.com 或 IP
                const char * service,           // "http" 或 "端口号"
                const struct addrinfo *hints,   // 初始化参数
                struct addrinfo **res);         // 地址链表

void freeaddrinfo(struct addrinfo *res);

const char *gai_strerror(int errcode);

// 扩展
// The getaddrinfo() function combines the functionality provided by the __gethostbyname()__ and __getservbyname()__ functions into a single interface, but unlike the latter functions, getaddrinfo() is reentrant and allows programs to eliminate IPv4-versus-IPv6 dependencies.
```

## 2.2 socket

create an endpoint for communication

```
#include <sys/types.h>
#include <sys/socket.h>

int socket(int domain, int type, int protocol);
```
### domain

|~Name              |~Purpose                               |~Man page
|AF_UNIX, AF_LOCAL  |Local communication                    |unix(7)
|AF_INET            |IPv4 Internet protocols                |ip(7)
|AF_INET6           |IPv6 Internet protocols                |ipv6(7)
|AF_IPX             |IPX - Novell protocols
|AF_NETLINK         |Kernel user interface device           |netlink(7)
|AF_PACKET          |Low level packet interface             |packet(7)
|....               |....

### type

* SOCK_STREAM provides sequenced, reliable, two-way, connection-based byte streams.
* SOCK_DGRAM connectionless, unreliable messages of a fixed maximum length

### protocol

默认为0, 基于type选择合适的协议。

## 2.3 bind

```
#include <sys/types.h>
#include <sys/socket.h>

int bind(int sockfd, struct sockaddr *my_addr, int addrlen);
```

## 2.4 connect

```
#include <sys/types.h>
#include <sys/socket.h>

int connect(int sockfd, struct sockaddr *serv_addr, int addrlen);
```

## 2.5 listen

```
#include <sys/types.h>
#include <sys/socket.h>

int listen(int sockfd, int backlog);
```

## 2.6 accept

```
#include <sys/types.h>
#include <sys/socket.h>

int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
```
## 2.7 send(), sendto(), sendmsg() & recv(), recvfrom(), recvmsg()

```
#include <sys/types.h>
#include <sys/socket.h>

ssize_t send(int sockfd, const void *msg, int len, int flags);
ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
                const struct sockaddr *dest_addr, socklen_t addrlen);
ssize_t sendmsg(int sockfd, const struct msghdr *msg, int flags);

ssize_t recv(int sockfd, void *buf, int len, int flags);
ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                struct sockaddr *src_addr, socklen_t *addrlen);
ssize_t recvmsg(int sockfd, struct msghdr *msg, int flags);
```

recv()返回0，表示远端关闭了你的连接；
recv()返回大于0，表示实际读到并写入到缓冲区的byte数目；
recv()返回-1，表示出错，并设置errno

## 2.8 close() & shutdown()

```
#include <unistd.h>

int close(int fd);
```

```
#include <sys/socket.h>

int shutdown(int sockfd, int how);
// how:
//  SHUT_RD 不允许再接收数据
//  SHUT_WR 不允许再传送数据
//  SHUT_RDWR 不允许再传送与接收数据，等同于close()
```
## 2.9 select()

```
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

// timeout: 如果时间超时了，而select()还没有找到任何就绪的file descriptor时，
//          它会回传，让你可以继续做其他事情。也就是说在这之前select是阻塞的
int select(int numfds, fd_set *readfds, fd_set *writefds,
            fd_set *exceptfds, struct timeval *timeout);

struct timeval {
    int tv_sec;     // second
    int tv_usec;    // microseconds
};

FD_SET(int fd, fd_set *set);        // 将fd添加到set
FD_CLR(int fd, fd_set *set);        // 将fd从set移除
FD_ISSET(int fd, fd_set *set);      // 若fd在set中，返回true
FD_ZERO(fd_set *set);               // 将set清零
```
