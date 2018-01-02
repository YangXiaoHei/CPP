//
//  main.cpp
//  Practise_1_13
//
//  Created by YangHan on 2018/1/2.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    /**
     *  1.9
     */
    int sum = 0;
    for (int i = 50; i <= 100; i++)
        sum += i;
    printf("%d\n", sum);
    
    /**
     *  1.10
     */
    for (int i = 10; i >= 0; i--)
        printf("%d ", i);
    printf("\n");
    
    /**
     *  1.11
     */
    int v1, v2;
    cout << "请输入两个数字 : " << endl;
    cin >> v1 >> v2;
    if (v1 > v2) {
        printf("第一个数字不能大于第二个数字");
        return -1;
    }
    for (int i = v1; i <= v2; i++)
        printf("%d\n",i);
    
    return 0;
}
// output
/**
 *  3825
     10 9 8 7 6 5 4 3 2 1 0
     请输入两个数字 :
     1 4
     1
     2
     3
     4
 */
