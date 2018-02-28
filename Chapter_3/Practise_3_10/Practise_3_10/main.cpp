//
//  main.cpp
//  Practise_3_10
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string line, rel;
    
    cout << "input a line : " << endl;
    cin >> line;
    
    for (auto c : line)
        if (!ispunct(c))
            rel += c;
    
    cout << rel << endl;
    
    return 0;
}
