//
//  main.cpp
//  Learning
//
//  Created by YangHan on 2018/4/3.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

namespace YH4 {
    class A {
    public:
        A(int a, std::string s) : a(a), b(s) {}
        A(int a) : a(a) {}
        A(std::string s) : b(s) {}
        int a;
        std::string b;
    };
}

void fun(YH4::A a) {
    cout << a.a << endl;
    cout << a.b << endl;
}

int main(int argc, const char * argv[]) {
    
    fun(string("sdfsdf"));
    fun(5);
    
    return 0;
}
