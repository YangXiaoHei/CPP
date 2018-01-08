//
//  main.cpp
//  Practise_1_20
//
//  Created by YangHan on 2018/1/8.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include "Sales_item.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Sales_item items[4];
    cout << "录入书籍销售记录" << endl;
    for (int i = 0; i < 4; i++)
        cin >> items[i];
    cout << "录入的书籍销售记录信息如下" << endl;
    for (int i = 0; i < 4; i++)
        cout << items[i] << endl;
    return 0;
}
// output
/**
 *   录入书籍销售记录
     shijianjianshi 1 32
     santi 3 29
     c++primer 1 88
     algorithms4 1 59
     录入的书籍销售记录信息如下
     shijianjianshi 1 32 32
     santi 3 87 29
     c++primer 1 88 88
     algorithms4 1 59 59
     Program ended with exit code: 0
 */
