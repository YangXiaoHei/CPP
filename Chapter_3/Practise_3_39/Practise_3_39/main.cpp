//
//  main.cpp
//  Practise_3_39
//
//  Created by YangHan on 2018/3/1.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string s1("yanghan"), s2("lijie");
    cout << (s1 < s2) << endl;
    
    const char *c = "yanghan";
    const char *d = "lijei";
    cout << (strcmp(c, d) < 0) << endl;
    
    
    
    return 0;
}
