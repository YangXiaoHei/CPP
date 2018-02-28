//
//  main.cpp
//  Practise_3_19
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> v(10, 42);
    vector<int> v1{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    vector<int> v2;
    for (int i = 0; i < 10; i++) {
        v2.push_back(42);
    }
    // 很明显第一种更好
    
    return 0;
}
