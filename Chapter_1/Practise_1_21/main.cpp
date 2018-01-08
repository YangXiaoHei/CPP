//
//  main.cpp
//  Practise_1_21
//
//  Created by YangHan on 2018/1/8.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include "Sales_item.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Sales_item item1, item2;
    cout << "请输入两个ISBN号相同的书籍" << endl;
    cin >> item1 >> item2;
    if (item1.isbn() == item2.isbn()) {
        cout << item1 + item2 << endl;
    } else {
        cerr << "ISBN号必须相等!" << endl;
        return -1;
    }
    return 0;
}
// output
/**
 *  请输入两个ISBN号相同的书籍
     C++Primer 1 78
     C++Primer 2 45
     C++Primer 3 168 56
 */
