//
//  main.cpp
//  Text_Bookstore
//
//  Created by YangHan on 2018/1/8.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include "Sales_item.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Sales_item total;
    if (cin >> total) {
        Sales_item trans;
        while (cin >> trans) {
            if (total.isbn() == trans.isbn())
                total += trans;
            else {
                cout << total << endl;
                total = trans;
            }
        }
        cout << total << endl;
    } else {
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}
// output
/**
 *   yanghan 1 23
     yanghan 2 32
     lijie 4 78
     yanghan 3 87 29
     lijie 9 89
     zhanghaiyue 8 10
     lijie 13 1113 85.6154
     zhanghaiyue 8 80 10
 */
