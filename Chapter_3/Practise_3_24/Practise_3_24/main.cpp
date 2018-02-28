//
//  main.cpp
//  Practise_3_24
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
    print(a, sz);
    vector<int> v;
    for (int i = 0; i < sz; i++)
        v.push_back(a[i]);
    if (v.size() == 0) {
        cout << "没有元素" << endl;
    } else if (v.size() == 1) {
        cout << v[0] << endl;
    } else {
        for (auto it = v.cbegin(); it != v.cend() - 1; ++it)
            cout << *it + *(it + 1) << endl;
    }
   
    
    return 0;
}
