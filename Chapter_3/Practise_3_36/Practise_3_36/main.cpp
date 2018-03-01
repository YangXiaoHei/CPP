//
//  main.cpp
//  Practise_3_36
//
//  Created by YangHan on 2018/3/1.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool isArrayEqual(int *a, int *b, int a_sz, int b_sz) {
    if (a_sz != b_sz) return false;
    for (int i = 0; i < a_sz; i++)
        if (a[i] != b[i]) return false;
    return true;
}
bool isVectorEqual(const vector<int> &a, const vector<int> &b) {
    return a == b;
}

int main(int argc, const char * argv[]) {
    
    int a[] = {1, 2, 3, 4};
    int b[] = {2, 3, 4, 5};
    int c[] = {1, 2, 3, 4};
    cout << isArrayEqual(a, c, 4, 4) << endl;
    
    vector<int> v1, v2;
    for (int i = 0; i < 4; i++) {
        v1.push_back(a[i]);
        v2.push_back(c[i]);
    }
    cout << isVectorEqual(v1, v2) << endl;
    
    v1.clear();
    v2.clear();
    
    for (int i = 0; i < 4; i++) {
        v1.push_back(a[i]);
        v2.push_back(b[i]);
    }
    cout << isVectorEqual(v2, v1) << endl;
    
    return 0;
}
