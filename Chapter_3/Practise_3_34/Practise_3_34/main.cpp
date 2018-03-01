//
//  main.cpp
//  Practise_3_34
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int a[] = {0, 1, 2, 3, 4, 5, 6};
    int *p1 = a, *p2 = a + 5;
    p1 += (p2 - p1);
    // 等同于 p1 = p2
    cout << *p1 << endl;
    // 只要 p1 和 p2 是合法的，那么 p1 += (p2 - p1) 永远是合法的
    
    return 0;
}
