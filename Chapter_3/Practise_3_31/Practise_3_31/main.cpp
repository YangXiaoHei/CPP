//
//  main.cpp
//  Practise_3_31
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
