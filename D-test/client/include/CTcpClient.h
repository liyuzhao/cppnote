#ifndef __CTCPCLIENT_H__
#define __CTCPCLIENT_H__

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>


// TCP Client
class CTcpClient
{
public:
    int m_sockfd;
    CTcpClient();

    // 向服务器发起连接, serverip-服务器ip, port 通信端口
    bool ConnectToServer(const char *serverip, const int port);
    // 向对端发送报文
    int Send(const void *buf, const int buflen);
    // 接收对端的报文
    int Recv(void *buf, const int buflen);

    ~CTcpClient();
};



#endif // __CTCPCLIENT_H__