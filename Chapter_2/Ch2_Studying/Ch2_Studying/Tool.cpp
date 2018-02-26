//
//  Tool.cpp
//  Ch2_Studying
//
//  Created by YangHan on 2018/2/27.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include "Tool.hpp"

void char_binary_str(char a) {
    for (int i = 7; i >= 0; i--)
        printf("%-2d", (a >> i) & 1);
    printf("\n");
}
void short_binary_str(short a) {
    for (int i = 15; i >= 0; i--) {
        if ((i + 1) % 8 == 0 && i != 15) printf(" ");
        printf("%-2d", (a >> i) & 1);
    }
    printf("\n");
}
void int_binary_str(int a) {
    for (int i = 31; i >= 0; i--) {
        if ((i + 1) % 8 == 0 && i != 31) printf("  ");
        printf("%-2d", (a >> i) & 1);
    }
    printf("\n");
}
void long_binary_str(long a) {
    for (int i = 63; i >= 0; i--) {
        if ((i + 1) % 8 == 0 && i != 63) printf("  ");
        printf("%-2d", (int)((a >> i) & 1));
    }
    printf("\n");
}
void long_long_binary_str(long long a) {
    for (int i = 127; i >= 0; i--) {
        if ((i + 1) % 8 == 0 && i != 127) printf("  ");
        printf("%-2d", (int)((a >> i) & 1));
    }
    printf("\n");
}
void float_binary_str(float a) {
    union u_ {
        float f;
        struct s_ {
            unsigned int sign       : 1;
            unsigned int exp        : 8;
            unsigned int mantissa   : 23;
        } s;
    } u;
    u.f = a;
    printf("%-2d  ", u.s.sign);
    for (int i = 7; i >= 0; i--)
        printf("%-2d", (u.s.exp >> i) & 1);
    printf("  ");
    for (int i = 22; i >= 0; i--)
        printf("%-2d", (u.s.mantissa >> i) & 1);
    printf("\n");
}
void double_binary_str(double a) {
    
}

void char_hex_str(char a);
void short_hex_str(short a);
void int_hex_str(int a);
void long_hex_str(long a);
void long_long_hex_str(long long a);
void float_hex_str(float a);
void double_hex_str(double a);
