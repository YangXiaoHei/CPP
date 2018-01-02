//
//  main.cpp
//  Practise_1_18
//
//  Created by YangHan on 2018/1/2.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int cur = 0, val = 0, cnt;
    if (cin >> cur) {
        cnt = 1;
        while (cin >> val) {
            if (cur != val) {
                cout << cur << " occurs " << cnt << " times " << endl;
                cur = val;
                cnt = 1;
                continue;
            }
            cnt++;
        }
        cout << cur << " ocurrs " << cnt << " times " << endl;
    }
    return 0;
}
// output
/**
 *   1 2 3 4
     1 occurs 1 times
     2 occurs 1 times
     3 occurs 1 times
     4 ocurrs 1 times
 
     1 1 1 1
     1 ocurrs 4 times
 */
