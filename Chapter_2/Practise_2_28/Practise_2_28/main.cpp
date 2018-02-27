//
//  main.cpp
//  Practise_2_28
//
//  Created by YangHan on 2018/2/27.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    // a
    {
//        int i, *const cp; 常量指针必须被初始化
    }
    // b
    {
//        int *p1, *const p2; 常量指针必须被初始化
    }
    // c
    {
//        const int ic, &r = ic;
        // const 变量必须被初始化
    }
    // d
    {
//        const int *const p3;  常量指针必须被初始化
    }
    // e
    {
        const int *p; // 指向常量的指针不一定需要被初始化
    }
    
    
    return 0;
}
