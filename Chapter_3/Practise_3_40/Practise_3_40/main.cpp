//
//  main.cpp
//  Practise_3_40
//
//  Created by YangHan on 2018/3/2.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    char a[] = "yanghan";
    char b[] = "lijie";
    char c[13] = {};
    strcpy(c, a);
    strcat(c, b);
    cout << c << endl;
    return 0;
}
