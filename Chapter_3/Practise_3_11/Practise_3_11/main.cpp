//
//  main.cpp
//  Practise_3_11
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    /**
     *  不合法，使用 const 修饰的 string 对象不可更改
     */
    
   const string s = "Keep out!";
    
    for (auto &c : s) {
        c = 'X';
    }
    cout << s << endl;
    
    
    return 0;
}
