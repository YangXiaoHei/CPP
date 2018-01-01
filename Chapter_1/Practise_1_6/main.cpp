//
//  main.cpp
//  Practise_1_6
//
//  Created by YangHan on 2018/1/1.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    /**
     *  不合法
     因为 ; 是一行语句的分隔符，在分隔符后继续使用 << 这个双目运算符，然后并没有为它提供左值
     会报编译错误
     */
    return 0;
}
