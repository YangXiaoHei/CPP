//
//  main.cpp
//  Practise_2_30
//
//  Created by YangHan on 2018/2/27.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    const int v2 = 0;  // 顶层 const
    
    int v1 = v2;
    
    int *p1 = &v1, &r1 = v1;
    
    int i = 0;
    
    // 底层 const         // 顶层 const
    const int *p2 = &v2, *const p3 = &i, &r2 = v2;
    
    return 0;
}
