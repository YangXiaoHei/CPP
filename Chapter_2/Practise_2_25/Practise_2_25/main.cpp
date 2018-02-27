//
//  main.cpp
//  Practise_2_25
//
//  Created by YangHan on 2018/2/27.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    // a
    {
        int* ip, i, &r = i;
    }
    // b
    {
        int i, *ip = 0;
    }
    // c
    {
        int* ip, ip2;
    }
    
    return 0;
}
