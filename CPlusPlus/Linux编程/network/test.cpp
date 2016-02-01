#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

using namespace std;

string sockaddr_inToString(struct sockaddr_in *addr)
{
    char str[INET_ADDRSTRLEN];
    inet_ntop(addr->sin_family, &(addr->sin_addr), str, sizeof str);
    stringstream ss;
    ss << str << ":" << addr->sin_port;
    return ss.str();
}

string sockaddr_in6ToString(struct sockaddr_in6 *addr)
{
    char str[INET6_ADDRSTRLEN];
    inet_ntop(addr->sin6_family, &(addr->sin6_addr), str, sizeof str);
    stringstream ss;
    ss << str << ":" << addr->sin6_port;
    return ss.str();
}

string sockaddrToString(struct sockaddr *addr)
{
    if(NULL == addr) return "null";

    if(AF_INET == addr->sa_family)
    {
        return sockaddr_inToString((struct sockaddr_in*)addr);
    }
    else if(AF_INET6 == addr->sa_family)
    {
        return sockaddr_in6ToString((struct sockaddr_in6*)addr);
    }

    return "error";
}

string addrinfoToString(struct addrinfo *servinfo)
{
    if(NULL == servinfo) return "null";

    string strTmp = sockaddrToString(servinfo->ai_addr);
    string strNext = (NULL == servinfo->ai_next ? "NULL" : "T");
    stringstream ss;
    ss << "ai_flags:\t" << servinfo->ai_flags << endl
        << "ai_family:\t" << servinfo->ai_family << endl
        << "ai_socktype:\t" << servinfo->ai_socktype << endl
        << "ai_protocol:\t" << servinfo->ai_protocol << endl
        << "ai_addrlen:\t" << servinfo->ai_addrlen << endl
        << "ai_addr:\t" << strTmp << endl
        << "ai_canonname:\t" << servinfo->ai_canonname << endl
        << "ai_next:\t" << strNext << endl;

    return ss.str();
}

int main()
{
    struct addrinfo hints;
    struct addrinfo *servinfo = NULL;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int iRet = getaddrinfo(NULL, "80", &hints, &servinfo);
    if(0 != iRet)
    {
        cerr << "getadrinfo error: " << gai_strerror(iRet) << endl;
        exit(1);
    }

    while(NULL != servinfo)
    {
        cout << "--------------------------->" << endl;
        cout << addrinfoToString(servinfo) << endl;
        servinfo = servinfo->ai_next;
    }

    freeaddrinfo(servinfo);

    return 0;
}
