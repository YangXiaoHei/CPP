//
//  main.cpp
//  Practise_3_30
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    /**
     *  数组越界
     */
    constexpr size_t array_size = 10;
    int ia[array_size];
    for (size_t ix = 1; ix <= array_size; ++ix) {
        ia[ix] = ix;
    }
    
    return 0;
}
