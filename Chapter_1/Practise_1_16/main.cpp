//
//  main.cpp
//  Practise_1_16
//
//  Created by YangHan on 2018/1/2.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int a[10];
    for (int i = 0; i < 10; i++)
        cin >> a[i];
    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum += a[i];
    printf("总计是 : %d\n", sum);
    
    return 0;
}
// output
/**
 *  1 2 3 4 5 6 7 8 9 10
    总计是 : 55
 */
