//
//  main.cpp
//  Practise_2_5
//
//  Created by YangHan on 2018/2/27.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    ////////////////////////////////////////////////////////////////
    cout << 'a' << endl; // char
    cout << L'a' << endl; // 宽字符
    cout << "a" << endl; // 字符串
    cout << L"a" << endl;
    
    
    ////////////////////////////////////////////////////////////////
    /**
     *  10      int
        10u     unsigned int
        10L     long
        012     unsigned int
        0xC     unsigned int
     */
    
    ////////////////////////////////////////////////////////////////
    cout << 3.14 << endl;   // double
    cout << 3.14f << endl;  // float
    cout << 3.14L << endl;  // long double
    
    ////////////////////////////////////////////////////////////////
    /**
     *  10      int
        10u     unsigned int
        10.     double
        10e-2   double
     */
    cout << 10e-2 << endl;
 
    return 0;
}
