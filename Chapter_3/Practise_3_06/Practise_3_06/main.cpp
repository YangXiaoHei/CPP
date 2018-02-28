//
//  main.cpp
//  Practise_3_06
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

void convert(string &s) {
    for (auto &c : s)
        c = 'X';
}

int main(int argc, const char * argv[]) {
    string s("haha");
    
    convert(s);
    
    cout << s << endl;
    
    return 0;
}
