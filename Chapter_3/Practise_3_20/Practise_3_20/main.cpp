//
//  main.cpp
//  Practise_3_20
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Tool.hpp"

using namespace std;

void originalAnswer() {
    int lo = 10, hi = 20;
    int *a = ints(lo, hi);
    int sz = hi - lo + 1;
    print(a, sz);
    vector<int> v;
    for (int i = 0; i < sz; i++)
        v.push_back(a[i]);
    
    if      (v.size() == 0) cout << "向量中没有数据" << endl;
    else if (v.size() == 1) cout << v[0] << endl;
    else {
        for (decltype(v.size()) i = 0; i < v.size() - 1; i++) {
            cout << v[i] + v[i + 1] << endl;
        }
    }
    delete a;
}

void modifiedAnswer() {
    int lo = 10, hi = 20;
    int *a = ints(lo, hi);
    int sz = hi - lo + 1;
    print(a, sz);
    vector<int> v;
    for (int i = 0; i < sz; i++)
        v.push_back(a[i]);
    
    if      (v.size() == 0) cout << "向量中没有数据" << endl;
    else if (v.size() == 1) cout << v[0] << endl;
    else {
        int i = 0, j = sz - 1;
        while (i < j)
            cout << v[i++] + v[j--] << endl;
        if (i == j)
            cout << v[i] << endl;
    }
    delete a;
}

int main(int argc, const char * argv[]) {
    modifiedAnswer();
    return 0;
}
