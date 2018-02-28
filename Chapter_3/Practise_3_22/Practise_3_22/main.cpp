//
//  main.cpp
//  Practise_3_22
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    string text("yanghan");
    for (auto it = text.begin(); it != text.end(); ++it) {
        *it = toupper(*it);
    }
    cout << text << endl;
    
    return 0;
}
