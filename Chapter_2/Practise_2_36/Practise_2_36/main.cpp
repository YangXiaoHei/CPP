//
//  main.cpp
//  Practise_2_36
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int a = 3, b = 4;
    decltype(a) c = a; // c 是 int 类型
    decltype((b)) d = a; // d 是引用类型
    ++c;
    ++d;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    
    return 0;
}
/**
 *   4
     4
     4
     4
 */
