//
//  main.cpp
//  Practise_1_24
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
            if (val.isbn() == cur.isbn()) ++cnt;
            else {
                cout << "ISBN为 " << cur.isbn() << " 的书籍有 " << cnt << "本" << endl;
                cur = val;
                cnt = 1;
            }
        }
        cout << "ISBN为 " << cur.isbn() << " 的书籍有 " << cnt << "本" << endl;
    }
    return 0;
}
// output
/**
 *   yanghan 1 39
     lijie 2 50
     ISBN为 yanghan 的书籍有 1本
     zhuyangkai 3 89
     ISBN为 lijie 的书籍有 1本
     zhuyangkai 10 90
     zhuyangkai 12 89
     zhuyangkai 11  67
     zhanghaiyue 6 10
     ISBN为 zhuyangkai 的书籍有 4本
     ISBN为 zhanghaiyue 的书籍有 1本
 */
