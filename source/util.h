//
// Created by zhangsong on 2020/11/17.
//

#ifndef ZSCSOKECT_UTIL_H
#define ZSCSOKECT_UTIL_H

#include "constant.h"

extern void strToBcd(BYTE str[], BYTE bcd[]);
extern void ByteToHexStr(char *tarBuff, const unsigned char *srcBuff, unsigned int len);
extern void BytetoBCD(unsigned char *tarBuff, const unsigned char *srcBuff, unsigned short len);
extern void HexStrToByte(unsigned char *tarBuff, const char *srcBuff, unsigned int len);
#endif //ZSCSOKECT_UTIL_H
