//
//  main.cpp
//  Practise_1_11
//
//  Created by YangHan on 2018/1/1.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    cout << "请输入一个范围 : " << endl;
    int lo, hi;
    cin >> lo >> hi;
    if (lo > hi) {
        cout << "lo 不能比 hi 大";
        return -1;
    }
    while (lo <= hi)
        cout << lo++ << endl;
    return 0;
}
// output
/**
 *  请输入一个范围 :
    3 20
     3
     4
     5
     6
     7
     8
     9
     10
     11
     12
     13
     14
     15
     16
     17
     18
     19
     20
 */
