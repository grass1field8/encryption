//
//  main.cpp
//  rsa
//
//  Created by 黄佳睿 on 14-11-16.
//  Copyright (c) 2014年 黄佳睿. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "RSA.h"
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    RSA RSAInstance;
    int e[MAX], d[MAX], n[MAX];
    RSAInstance.RSAKey();
    cout<<"p:";
    for (int i = 0; i < RSAInstance.p[MAX-1]; i++) {
        cout<<RSAInstance.p[i];
    }
    cout<<endl;
    cout<<"q:";
    for (int i = 0; i < RSAInstance.q[MAX-1]; i++) {
        cout<<RSAInstance.q[i];
    }
    cout<<endl;
    cout<<"input e in decimal:"<<endl;
    char  c;
    int j = 0;
    while (1) {
        c = getchar();
        if (c == '\n') {
            break;
        }
        RSAInstance.e[j] = c - '0';
        j++;
    }
    RSAInstance.e[MAX-1] = j;
    RSAInstance.e[MAX-2] = 1;
    RSAInstance.getP();
    
    cout<<"d:";
    for (int i = 0; i < RSAInstance.d[MAX-1]; i++) {
        cout<<RSAInstance.d[i];
    }
    cout<<endl;
    
    fstream inf, outf;
    inf.open("/Users/hjr/code/rsa/in");
    outf.open("/Users/hjr/code/rsa/out");
    string in;
    inf>>in;
    cout<<"Input 0 to cipher, 1 to incipher:"<<endl;
    int i;
    cin>>i;
    if (i == 0) {
        
        RSAInstance.tdecrypto(RSAInstance.e, RSAInstance.n, in);
    }
    
    
    
    
    
    
}
