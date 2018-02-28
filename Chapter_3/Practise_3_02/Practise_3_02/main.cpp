//
//  main.cpp
//  Practise_3_02
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

void originalAnswer() {
    string line;
    while (getline(cin, line))
        cout << line << endl;
}

void modifiedAnswer() {
    string word;
    while (cin >> word)
        cout << word << endl;
}

int main(int argc, const char * argv[]) {
    modifiedAnswer();
    return 0;
}
