//
//  main.cpp
//  Practise_3_12
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    // a
    {
        vector<vector<int>> ivec;
    }
    // b
    {
        vector<vector<int>> ivec;
        vector<string> svec = ivec;
    }
    // c
    {
        vector<string> svec(10, "null");
    }
    
    
    return 0;
}
