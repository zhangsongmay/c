#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include "zssocket.h"
#include "constant.h"
#include "util.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("please input two params like 127.0.0.1 8080\n");
    }
    char *ip = argv[1];
    int port = (int) strtol(argv[2], NULL, 10);

    int sock = zsConnect(ip, port);
    if (sock > 0) {
        //获取用户输入的字符串并发送给服务器
        char bufSend[BUF_SIZE] = {0};
        printf("Input a string: ");
        scanf("%s", bufSend);
        size_t len = strlen(bufSend);
        size_t lenB = strlen(bufSend) / 2;
        printf("str len %zu\n", len);
        unsigned char *bytes = (unsigned char *) malloc(lenB);
        printf("size of bytes = %ld\n", lenB);
        memset(bytes, 0, len);
        HexStrToByte(bytes, bufSend, len);
        send(sock, bytes, lenB, 0);
        free(bytes);
        //读取服务器传回的数据
        unsigned char bufRead[BUF_SIZE] = {0};
        printf("wait server send datas...\n");
        int recvLen = recv(sock, bufRead, BUF_SIZE, 0);
        printf("recvLen=%d\n", recvLen);
        for (int i = 0; i < recvLen; i++) {
            printf("%02X", bufRead[i]);
        }
        printf("\n");

        close(sock);
        printf("closed sock=%d success\n", sock);
    }
    return 0;
}
