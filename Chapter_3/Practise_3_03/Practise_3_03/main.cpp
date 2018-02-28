//
//  main.cpp
//  Practise_3_03
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string word;
    while (cin >> word)
        cout << word << endl;
    
    /**
     *  cin 将标准输入流读入到 word，直到遇到空格，然后返回 cin 对象的引用
     */
    
    string line;
    while (getline(cin, line))
        cout << line << endl;
    
    /**
     *  getline 将标准输入流读入到 line, 直到遇到回车，然后返回 cin 对象的引用
     */
    
    return 0;
}
