//
//  main.cpp
//  Practise_2_31
//
//  Created by YangHan on 2018/2/27.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    const int v2 = 0;
    
    int v1 = v2;
    
    int *p1 = &v1, &r1 = v1;
    
    int i = 10;
    
    const int *p2 = &v2, *const p3 = &i, &r2 = v2;
    
    r1 = v2;
    
//    p1 = p2;    // 错误
    p2 = p1;
    
//    p1 = p3; 错误
    
    p2 = p3;
    
    return 0;
}
