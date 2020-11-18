//
// Created by zhangsong on 2020/11/17.
//

#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include "zssocket.h"

int zsConnect(const char *ip, int port) {
    //创建套接字
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    //向服务器（特定的IP和端口）发起请求
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr(ip);  //具体的IP地址
    serv_addr.sin_port = htons(port);  //端口
    int con = connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (con >= 0) {
        printf("connect %s port %d success, sock=%d\n", ip, port, sock);
        return sock;
    } else {
        printf("connect %s port %d, sock=%d failed\n", ip, port, sock);
        close(sock);
        printf("closed sock=%d success\n", sock);
        return -1;
    }
}