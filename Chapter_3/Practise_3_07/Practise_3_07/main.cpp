//
//  main.cpp
//  Practise_3_07
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string s("haha");
    
    for (char &c : s)
        c = 'X';
    
    cout << s << endl;
    
    return 0;
}
