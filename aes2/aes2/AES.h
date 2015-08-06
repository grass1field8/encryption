//
//  AES.h
//  aes2
//
//  Created by 黄佳睿 on 14-11-17.
//  Copyright (c) 2014年 黄佳睿. All rights reserved.
//

#ifndef __aes2__AES__
#define __aes2__AES__

#include <stdio.h>
class AES
{
public:
    AES(unsigned char* key);
    virtual ~AES();
    unsigned char* Cipher(unsigned char* input);
    unsigned char* InvCipher(unsigned char* input);
private:
    unsigned char Sbox[256];
    unsigned char InvSbox[256];
    unsigned char w[11][4][4];
    void KeyExpansion(unsigned char* key, unsigned char w[][4][4]);
    unsigned char FFmul(unsigned char a, unsigned char b);
    void SubBytes(unsigned char state[][4]);
    void ShiftRows(unsigned char state[][4]);
    void MixColumns(unsigned char state[][4]);
    void AddRoundKey(unsigned char state[][4], unsigned char k[][4]);
    void InvSubBytes(unsigned char state[][4]);
    void InvShiftRows(unsigned char state[][4]);
    void InvMixColumns(unsigned char state[][4]);
};


#endif /* defined(__aes2__AES__) */
