//
//  main.cpp
//  Practise_2_10
//
//  Created by YangHan on 2018/2/27.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 *  类指定过默认初始化值
 */
string global_str;
/**
 *  定义在任何函数体之外的内置类型被初始化为 0
 */
int global_int;

int main(int argc, const char * argv[]) {
    /**
     *  定义在函数体内部的变量不被初始化
     */
    int local_int;
    /**
     *  类指定过默认初始化值
     */
    string local_str;
    
    cout << global_int << endl;
    cout << global_str << endl;
    
    cout << local_int << endl;
    cout << local_str << endl;
    
    return 0;
}
