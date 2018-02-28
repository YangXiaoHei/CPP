//
//  main.cpp
//  Practise_2_38
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    const int i = 10;
    int j = 20;
    
    /**
     *  decltype 和 auto 相同的推断
     */
    {
        decltype(j) a = 10;
        auto b = j;
        
        a = 100;
        b = 100;
        
        cout << a << endl;
        cout << b << endl;
    }
    /**
     *  decltype 和 auto 不同的推断
     */
    {
        decltype(i) a = 10;
        auto b = i;
        
//        a = 20; 不能修改 a 的值，因为 a 是一个 const int
        b = 20;
        
        cout << a << endl;
        cout << b << endl;
    }
    return 0;
}
/**
 *   100
     100
     10
     20
 */
