//
//  main.cpp
//  Practise_2_16
//
//  Created by YangHan on 2018/2/27.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int     i = 0,   &r1 = i;
    double  d = 0,   &r2 = d;
    
    // a
    {
        r2 = 3.14159;
    }
    cout << i << endl;
    cout << d << endl;
    // b
    {
        r2 = r1;
    }
    cout << i << endl;
    cout << d << endl;
    // c
    {
        i = r2;
    }
    cout << i << endl;
    cout << d << endl;
    // d
    {
        r1 = d;
    }
    cout << i << endl;
    cout << d << endl;
    
    return 0;
}
