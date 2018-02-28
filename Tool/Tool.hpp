//
//  Tool.hpp
//  Ch2_Studying
//
//  Created by YangHan on 2018/2/27.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#ifndef Tool_hpp
#define Tool_hpp

#include <stdio.h>

int *ints(int lo, int hi);
int *ints(int size, int lo, int hi);
int *ascendInts(int lo, int hi);
int *descendInts(int hi, int lo);
void print(int *a, int size);

void char_binary_str(char a);
void short_binary_str(short a);
void int_binary_str(int a);
void long_binary_str(long a);
void long_long_binary_str(long long a);
void float_binary_str(float a);
void double_binary_str(double a);

void char_hex_str(char a);
void short_hex_str(short a);
void int_hex_str(int a);
void long_hex_str(long a);
void long_long_hex_str(long long a);
void float_hex_str(float a);
void double_hex_str(double a);

#endif /* Tool_hpp */
