//
//  main.cpp
//  Text_if
//
//  Created by YangHan on 2018/1/2.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int currVal = 0, val = 0;
    if (cin >> currVal) {
        int cnt = 1;
        while (cin >> val) {
            if (val == currVal) ++cnt;
            else {
                cout << currVal << " occurs " << cnt << " times " << endl;
                currVal = val;
                cnt = 1;
            }
        }
        cout << currVal << " ocurrs " << cnt << " times " << endl;
    }
    return 0;
}
