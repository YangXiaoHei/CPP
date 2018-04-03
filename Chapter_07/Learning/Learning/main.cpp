//
//  main.cpp
//  Learning
//
//  Created by YangHan on 2018/4/3.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include "Sales_data.hpp"
#include "Screen.hpp"

int main(int argc, const char * argv[]) {
    
    Screen s(50, 50, 'c');
//    s.display(cout);
    s.set('a').display(cout);
    
    return 0;
}
