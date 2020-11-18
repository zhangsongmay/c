//
// Created by zhangsong on 2020/11/17.
//

#ifndef ZSCSOKECT_CONSTANT_H
#define ZSCSOKECT_CONSTANT_H

#define HEAD_TAIL_FLAG 0X7E
#define BUF_SIZE 1024

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;

typedef struct {
    WORD msgId; // 消息 ID
    WORD msgAttr; // 消息体属性
    BYTE did[6]; // 终端手机号
    WORD msgStreamNo; //消息流水号
} msgHead;

#endif //ZSCSOKECT_CONSTANT_H
