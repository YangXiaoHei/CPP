//
//  main.cpp
//  Practise_2_18
//
//  Created by YangHan on 2018/2/27.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int a = 100, d = 200;
    
    int *p = &a;
    
    p = &d;
    
    *p = 300;
    
    cout << a << " " << d << endl;
    
    
    
    return 0;
}
