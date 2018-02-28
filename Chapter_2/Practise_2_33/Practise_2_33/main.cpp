//
//  main.cpp
//  Practise_2_33
//
//  Created by YangHan on 2018/2/27.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int i = 0, &r = i;
    auto a = r;
    
    const int ci = i, &cr = ci;
    auto k = ci, &l = i;
    
    auto &m = ci, *p = &ci;
    
    return 0;
}
