//
//  Tool.cpp
//  Ch2_Studying
//
//  Created by YangHan on 2018/2/27.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include "Tool.hpp"
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

int *ints(int lo, int hi) {
    srand((unsigned)time(NULL));
    int size = hi - lo + 1;
    int *arr = new int[size];
    int j = 0, i = lo;
    while (i <= hi) arr[j++] = i++;
    for (int k = 0; k < size; k++) {
        int r = rand() % (size - k) + k;
        swap(arr + r, arr + k);
    }
    return arr;
}

void print(int *a, int size) {
    for (int i = 0; i < size; i++)
        printf("%-3d", a[i]);
    printf("\n");
}

int *ints(int size, int lo, int hi) {
    srand((unsigned)time(NULL));
    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (hi - lo + 1) + lo;
    }
    return arr;
}
int *ascendInts(int lo, int hi) {
    int size = hi - lo + 1;
    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = lo++;
    }
    return arr;
}
int *descendInts(int hi, int lo) {
    int size = hi - lo + 1;
    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = hi--;
    }
    return arr;
}

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
            unsigned int mantissa   : 23;
            unsigned int exp        : 8;
            unsigned int sign       : 1;
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
    union u_ {
        float f;
        struct s_ {
            unsigned long mantissa   : 52;
            unsigned long exp        : 11;
            unsigned long sign       : 1;
        } s;
    } u;
    u.f = a;
    printf("%-2d  ", u.s.sign);
    for (int i = 10; i >= 0; i--)
        printf("%-2d", (u.s.exp >> i) & 1);
    printf("  ");
    for (int i = 51; i >= 0; i--)
        printf("%-2d", (int)((u.s.mantissa >> i) & 1));
    printf("\n");
}

void char_hex_str(char a) {
    printf("%x\n", a);
}
void short_hex_str(short a) {
    printf("%x\n", a);
}
void int_hex_str(int a) {
    unsigned char *byte = (unsigned char *)&a;
    printf("%x %x\n",*(byte + 1), *byte);
}
void long_hex_str(long a) {
    unsigned char *byte = (unsigned char *)&a;
    printf("%x %x %x %x\n", *(byte + 3), *(byte + 2), *(byte + 1), *byte);
}
void long_long_hex_str(long long a) {
    unsigned char *byte = (unsigned char *)&a;
    for (int i = 7; i >= 0; i--)
        printf("%x ", byte[i]);
    printf("\n");
}
void float_hex_str(float a) {
    unsigned char *byte = (unsigned char *)&a;
    for (int i = 3; i >= 0; i--)
        printf("%x ", byte[i]);
    printf("\n");
}
void double_hex_str(double a) {
    unsigned char *byte = (unsigned char *)&a;
    for (int i = 7; i >= 0; i--)
        printf("%x ", byte[i]);
    printf("\n");
}
