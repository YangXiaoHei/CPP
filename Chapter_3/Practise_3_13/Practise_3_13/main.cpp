//
//  main.cpp
//  Practise_3_13
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
        vector<int> v1; // 空的向量
    }
    // b
    {
        vector<int> v2(10); // v2 含有 10 个元素，每个都是 0
    }
    // c
    {
        vector<int> v3(10, 42); // v3 含有 10 个元素，每个都是 42
    }
    // d
    {
        vector<int> v4{10}; // v4 含有 1 个元素 10
    }
    // e
    {
        vector<int> v5{10, 42}; // v5 含有 2 个元素 10 和 42
    }
    // f
    {
        vector<string> v6{10}; // v6 含有 10 个空字符串
        cout << v6.size() << endl;
    }
    // g
    {
        vector<string> v7{10, "hi"}; // v7 含有 10 个字符串，都是 "hi"
    }
    
    
    return 0;
}
