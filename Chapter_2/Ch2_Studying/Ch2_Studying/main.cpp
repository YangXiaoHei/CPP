//
//  main.cpp
//  Ch2_Studying
//
//  Created by YangHan on 2018/2/26.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include "Tool.hpp"

using namespace std;

/**
 *  C++标准规定的尺寸的最小值
 
    bool        未定义
    char        8 bit
    wchar_t     16 bit
 
    char16_t    16 bit
    char32_t    32 bit  ---> 为 Unicode 字符集服务
 
    short       16 bit
    int         16 bit  ---> int 至少和 short 一样大
 
    long        32 bit
    long long   64 bit  ---> long 至少和 int 一样大
                        ---> long long 至少和 long 一样大
    float       6 位有效数字
    double      10 位有效数字
    long double 10 位有效数字
 
 */



void displayCurrentBits() {
    cout << (sizeof(bool) << 3) << endl;
    cout << (sizeof(char) << 3) << endl;
    cout << (sizeof(wchar_t) << 3) << endl;
    cout << (sizeof(char16_t) << 3) << endl;
    cout << (sizeof(char32_t) << 3) << endl;
    cout << (sizeof(short) << 3) << endl;
    cout << (sizeof(int) << 3) << endl;
    cout << (sizeof(long) << 3) << endl;
    cout << (sizeof(long long) << 3) << endl;
    cout << (sizeof(float) << 3) << endl;
    cout << (sizeof(double) << 3) << endl;
    cout << (sizeof(long double) << 3) << endl;
}

/**
 *  含有无符号类型的表达式
 
 */
void unsignedAndSigned() {
    unsigned u = 10;
    int i = -42;
    cout << "i      =   "; int_binary_str(i);
    cout << "u      =   "; int_binary_str(u);
    cout << "i + u  =   "; int_binary_str(u + i);
    cout << "i + u  =   " << i + u << endl;
    
    cout << endl;
    
    unsigned u1 = 42, u2 = 10;
    cout << "u2       =   "; int_binary_str(u2);
    cout << "u1       =   "; int_binary_str(u1);
    cout << "u2 - u1  =   "; int_binary_str(u2 - u1);
    cout << "u2 - u1  =   " << u2 - u1 << endl;
}

int main(int argc, const char * argv[]) {
    unsignedAndSigned();
    return 0;
}
