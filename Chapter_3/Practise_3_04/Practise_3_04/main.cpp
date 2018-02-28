//
//  main.cpp
//  Practise_3_04
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

void originalAnswer() {
    string s1, s2;
    cout << "input two string : " << endl;
    cin >> s1 >> s2;
    if      (s1 == s2) cout << s1 << " 和 " << s2 << " 相等" << endl;
    else if (s1 > s2)  cout << s1 << endl;
    else    cout << s2 << endl;
}
void modifiedAnswer() {
    string s1, s2;
    cout << "input two string : " << endl;
    cin >> s1 >> s2;
    if      (s1.size() == s2.size()) cout << s1 << " 和 " << s2 << " 长度相等 " << endl;
    else if (s1.size() > s2.size()) cout << s1 << endl;
    else    cout << s2 << endl;
}

int main(int argc, const char * argv[]) {
    
    modifiedAnswer();
    
    return 0;
}
