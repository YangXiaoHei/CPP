//
//  main.cpp
//  Second
//
//  Created by YangHan on 2018/4/22.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

namespace YH {
    
    void test()
    {
        int i = int();
        cout << i << endl;
        
        int *p = new int;  // *p 的值未定义
        cout << *p << endl;
        
        int *pp = new int();
        cout << *pp << endl; // *pp 使用值初始化
        
        // ppp 指向一个与 i 类型相同的对象，该对象用 obj 进行初始化
        auto ppp = new auto(i);
        cout << *ppp << endl;
    }
}

namespace YH1 {
    
    void test()
    {
        
    }
}

int main(int argc, const char * argv[]) {
    
    YH::test();
    
    return 0;
}
