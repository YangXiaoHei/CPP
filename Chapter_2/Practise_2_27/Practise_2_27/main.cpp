//
//  main.cpp
//  Practise_2_27
//
//  Created by YangHan on 2018/2/27.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    // a
    {
        int i = -1, &r = 0; // 错
    }
    // b
    {
        int i2 = 10;
        int *const p2 = &i2;
    }
    // c
    {
        const int i = -1, &r = 0;
    }
    // d
    {
        int i2 = 10;
        const int *const p3 = &i2;
    }
    // e
    {
        int i2 = 10;
        const int *p1 = &i2;
    }
    // f
    {
//        const int *const r2;  常量指针必须被初始化
    }
    // g
    {
        int i = 10;
        const int i2 = i, &r = i;
    }
    
    return 0;
}
