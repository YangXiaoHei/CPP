//
//  main.cpp
//  Practise_3_23
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Tool.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    int l = 10, h = 20, sz = h - l + 1;
    int *a = ints(l, h);
    vector<int> v;
    for (int i = 0; i < sz; i++)
        v.push_back(a[i]);
    for (auto it = v.begin(); it != v.end(); ++it)
        *it = *it * *it;
    for (auto it = v.cbegin(); it != v.cend(); ++it)
        cout << *it << " ";
    cout << endl;
    return 0;
}
