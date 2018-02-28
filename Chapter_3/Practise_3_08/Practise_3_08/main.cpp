//
//  main.cpp
//  Practise_3_08
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string s("haha");
    for (decltype(s.size()) i = 0; i < s.size(); i++)
        s[i] = 'X';
    cout << s << endl;
    
    string s1("yanghan");
    decltype(s1.size()) i = 0;
    while (i < s1.size())
        s1[i++] = 'X';
    cout << s1 << endl;
    
    return 0;
}
