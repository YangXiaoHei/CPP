//
//  main.cpp
//  Text_IO
//
//  Created by YangHan on 2018/1/1.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    std::cout << "Enter two numbers: " << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2 << " is "
    << v1 + v2 << std::endl;
    
    return 0;
}
