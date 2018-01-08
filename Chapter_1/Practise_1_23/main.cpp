//
//  main.cpp
//  Practise_1_23
//
//  Created by YangHan on 2018/1/8.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include "Sales_item.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Sales_item cur, val;
    if (cin >> cur) {
        int cnt = 1;
        while (cin >> val) {
            if (val.isbn() == cur.isbn())
                ++cnt;
            else {
                cout << "ISBN为" << cur.isbn()
                << "的书籍有 " << cnt << endl;
                cur = val;
                cnt = 1;
            }
        }
        cout << "ISBN为" << cur.isbn() << "的书籍有 " << cnt << endl;
    }
    return 0;
}
// output
/**
 *   yanghan 1 34
     lijie 2 32
     ISBN为yanghan的书籍有 1
     lijie 3 19
     lijie 9 10
     yangkaiyun 1 32
     ISBN为lijie的书籍有 3
     ISBN为yangkaiyun的书籍有 1
 */
