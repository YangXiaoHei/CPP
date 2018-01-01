//
//  main.cpp
//  Practise_1_8
//
//  Created by YangHan on 2018/1/1.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    // 正确
    cout << "/*";
    
    // 正确
    cout << "*/";
    
    //第一个双引号被注释掉
    cout << /* "*/" */;

    // 正确
    cout << /* "*/" /* "/*" */;
    return 0;
}
