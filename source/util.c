//
// Created by zhangsong on 2020/11/17.
//

#include "util.h"
#include "constant.h"

void strToBcd(BYTE str[], BYTE bcd[]) {
    bcd[0] = (BYTE) ((str[0] - '0') << 4) + (str[1] - '0');
    bcd[1] = (BYTE) ((str[2] - '0') << 4) + (str[3] - '0');
    bcd[2] = (BYTE) ((str[4] - '0') << 4) + (str[5] - '0');
    bcd[3] = (BYTE) ((str[6] - '0') << 4) + (str[7] - '0');
    bcd[4] = (BYTE) ((str[8] - '0') << 4) + (str[9] - '0');
    bcd[5] = (BYTE) ((str[10] - '0') << 4) + (str[11] - '0');
}

/*********************************
HEX/BCD/BYTE/之间的转换
**********************************/

/**
将srcBuff指向的len个字节的数据，按十六进制字符编码转换，并存于tarBuff中
*/
void ByteToHexStr(char *tarBuff, const unsigned char *srcBuff, unsigned int len) {
    char byte;

    while (len--) {
        byte = *srcBuff >> 4;
        *tarBuff++ = (byte > 9) ? (byte + 'A' - 10) : (byte + '0');

        byte = *srcBuff & 0x0F;
        *tarBuff++ = (byte > 9) ? (byte + 'A' - 10) : (byte + '0');

        ++srcBuff;
    }
    *tarBuff = 0;//空字符
}

/**
将无符号字符数据，转换为十六进制数据，并存于tarBuff中
*/
void BytetoBCD(unsigned char *tarBuff, const unsigned char *srcBuff, unsigned short len) {
    while (len--) {
        *tarBuff++ = (((*srcBuff / 10) % 10) << 4) | (*srcBuff % 10);
        ++srcBuff;
    }
}

/**
将srcBuff指向的len个长度的字符串数据，按十六进制字符编码转换为字符，并存于tarBuff中
*/
void HexStrToByte(unsigned char *tarBuff, const char *srcBuff, unsigned int len) {
    char byte;

    if (len % 2 == 1)
        --len;

    while (len) {
        byte = *srcBuff > '9' ? (*srcBuff - 'A' + 10) : (*srcBuff - '0');
        ++srcBuff;
        byte <<= 4;

        byte |= *srcBuff > '9' ? (*srcBuff - 'A' + 10) : (*srcBuff - '0');
        ++srcBuff;

        *tarBuff++ = byte;
        len -= 2;
    }
}
