//
//  main.cpp
//  Practise_3_05
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

void originalAnswer() {
    string word, rel;
    while (cin >> word && word != "end")
        rel += word;
    cout << rel << endl;
}

void modifiedAnswer() {
    string word, rel;
    while (cin >> word && word != "end")
        rel += (word + " ");
    cout << rel << endl;
}

int main(int argc, const char * argv[]) {
    modifiedAnswer();
    return 0;
}
