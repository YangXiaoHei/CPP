//
//  main.cpp
//  Practise_3_42
//
//  Created by YangHan on 2018/3/2.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> iv{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a[10];
    for (int i = 0; i < iv.size(); i++) {
        a[i] = iv[i];
    }
    for (int i = 0; i < 10; i++) {
        cout << a[i] << endl;
    }
    
    return 0;
}
