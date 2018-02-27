//
//  main.cpp
//  Practise_2_21
//
//  Created by YangHan on 2018/2/27.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int i = 0;
    
    // a
    {
//        double *dp = &i; 非法
    }
    // b
    {
//        int *ip = i;  非法
    }
    // c
    {
        int *p = &i;
    }
    
    
    return 0;
}
