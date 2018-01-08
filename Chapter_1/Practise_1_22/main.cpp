//
//  main.cpp
//  Practise_1_22
//
//  Created by YangHan on 2018/1/8.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include "Sales_item.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Sales_item items[6];
    cout << "请录入 6 册书籍" << endl;
    for (int i = 0; i < 6; i++)
        cin >> items[i];
    Sales_item item = items[0];
    for (int i = 1; i < 6; i++) {
        if (item.isbn() != items[i].isbn()) {
            cerr << "ISBN号必须相等" << endl;
            return -1;
        }
        item = item + items[i];
    }
    cout << "输入的所有书籍和为 : " << item << endl;
    return 0;
}
// output
/**
 *   请录入 6 册书籍
     yanghan 1 32
     yanghan 2 35
     yanghan 3 80
     yanghan 9 87
     yanghan 10 75
     yanghan 11 70
     输入的所有书籍和为 : yanghan 36 2645 73.4722
 */
