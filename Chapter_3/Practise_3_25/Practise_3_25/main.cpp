//
//  main.cpp
//  Practise_3_25
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Tool.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    int l = 0, h = 100, sz = 40;
    int *scores = ints(sz, l, h);
    print(scores, sz);
    
    vector<int> scorev;
    
    int *grades = (int *)calloc(11, sizeof(int));
    print(grades, 11);
    
    for (int i = 0; i < sz; i++) {
        scorev.push_back(scores[i]);
    }
    
    for (auto it = scorev.cbegin(); it != scorev.cend(); ++it)
        grades[*it / 10]++;
    
    print(grades, 11);
    
    return 0;
}
