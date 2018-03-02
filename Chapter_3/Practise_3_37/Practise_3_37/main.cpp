//
//  main.cpp
//  Practise_3_37
//
//  Created by YangHan on 2018/3/1.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;
    while (*cp) {
        cout << *cp << endl;
        ++cp;
    }
    
    
    return 0;
}
