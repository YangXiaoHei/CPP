//
//  main.cpp
//  Practise_1_19
//
//  Created by YangHan on 2018/1/2.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int a, b;
    cin >> a >> b;
    if (a > b) {
        cout << "a 不能大于 b" << endl;
        return -1;
    }
    for (int i = a; i <= b; i++)
        cout << i << endl;
    return 0;
}
// output
/**
 *  1 3
     1
     2
     3
 */
