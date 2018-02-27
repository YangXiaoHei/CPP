//
//  main.cpp
//  Practise_2_17
//
//  Created by YangHan on 2018/2/27.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int i, &ri = i;
    i = 5; ri = 10;
    cout << i << " " << ri << endl;
    
    return 0;
}
