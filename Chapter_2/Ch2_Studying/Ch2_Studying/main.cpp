//
//  main.cpp
//  Ch2_Studying
//
//  Created by YangHan on 2018/2/26.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

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

int main(int argc, const char * argv[]) {
    displayCurrentBits();
    
    
    return 0;
}
