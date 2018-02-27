//
//  main.cpp
//  Practise_2_3
//
//  Created by YangHan on 2018/2/27.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    unsigned u = 10, u2 = 42;
    cout << u2 - u << endl;   // 32
    cout << u - u2 << endl;   // 2^32 - 32
    
    int i = 10, i2 = 42;
    cout << i2 - i << endl;  // 32
    cout << i - i2 << endl;  // -32
    cout << i - u << endl;   // 0
    cout << u - i << endl;   // 0
    
    return 0;
}
