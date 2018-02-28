//
//  main.cpp
//  Practise_3_27
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

int txt_size() { return 1; }

int main(int argc, const char * argv[]) {
    
    unsigned buf_size = 1024;
    // a
    {
        int ia[buf_size];
    }
    // b
    {
        int ia[4 * 7 - 14];
    }
    // c
    {
        int ia[txt_size()];
    }
    // d
    {
//        char st[11] = "fundamental"; // 还有 '\0' 的位置
    }
    
    return 0;
}
