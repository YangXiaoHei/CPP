//
//  main.cpp
//  Practise_2_20
//
//  Created by YangHan on 2018/2/27.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int i = 42;
    
    int *p1 = &i;
    
    *p1 = *p1 * *p1;
    
    cout << i << endl;
    
    return 0;
}
