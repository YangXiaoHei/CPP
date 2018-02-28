//
//  main.cpp
//  Practise_3_32
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = i;
    }
    int b[10];
    for (int i = 0; i < 10; i++) {
        b[i] = a[i];
    }
    
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    vector<int> vcopy(v);
    
    
    
    return 0;
}
