//
//  main.cpp
//  aes2
//
//  Created by 黄佳睿 on 14-11-17.
//  Copyright (c) 2014年 黄佳睿. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "AES.h"
using namespace std;

int main(int argc, const char * argv[]) {
    int inf, outf, keyf;
    string path;
    cout<<"Input key file path:"<<endl;
    cin>>path;
    keyf = open(path.c_str(), O_RDWR);
    cout<<"Input input file path:"<<endl;
    cin>>path;
    inf = open(path.c_str(), O_RDWR);
    cout<<"Input output file path:"<<endl;
    cin>>path;
    outf = open(path.c_str(), O_RDWR);
    unsigned char input[16], key[16];
    read(inf, input, sizeof(input));
    read(keyf, input, sizeof(key));
    AES aesInstance(key);
    int i;
    cout<<"input 0 to cipher, 1 to Incipher:"<<endl;
    cin>>i;
    if (i == 0) {
        aesInstance.Cipher(input);
    }
    else{
        aesInstance.InvCipher(input);
    }
    write(outf, input, sizeof(input));
    close(inf);
    close(outf);
    close(keyf);
    return 0;
}
