//
//  main.cpp
//  Practise_2_8
//
//  Created by YangHan on 2018/2/27.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    /**
     *  思路 : 先用 cout << (int)'M' << (int)'\n' << (int)'\t' << endl;
        找出字符对应的 ASCLL 码十进制的值，手动转成八进制后使用转义斜杆
     */
    
    cout << "2\115\12";
    
    cout << "2\11\115\12";
    
    return 0;
}
