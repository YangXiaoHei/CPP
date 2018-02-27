//
//  main.cpp
//  Practise_2_29
//
//  Created by YangHan on 2018/2/27.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    // a
    {
        int i;
        const int ic = 10;
        i = ic;
    }
    // b
    {
        int i = 10;
        const int * const p = &i;
//        int *p1 = p; 错误
        
        int j = 20;
        const int *p2 = &j;
//        int *p3 = p2;  错误
        
        int k = 30;
        int * const p3 = &k;
        int *p4 = p3;
    }
    // c
    {
        const int ic = 10;
//        int *p1 = &ic;  错误
    }
    // d
    {
        const int ic = 10;
        const int * const p3 = &ic;
    }
    // e
    {
        int i = 10;
        int *p1 = &i;
        int *const p2 = p1;
    }
    // f
    {
        const int ic = 10;
        const int * const p3 = &ic;
    }
    
    
    return 0;
}
