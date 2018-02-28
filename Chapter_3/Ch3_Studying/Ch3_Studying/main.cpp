//
//  main.cpp
//  Ch3_Studying
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

void definitionAndInitilizeString() {
    string s1;
    string s2 = s1;
    string s3 = "hiya";
    string s4(10, 'c');
    string s5(s3);
    string s6("yanghan");
}

void readStringUtilSpace() {
    string word;
    // 遇到空格就停止读取
    while (cin >> word)
        cout << word << endl;
}
void readStringUtilCarriage() {
    string line;
    // 遇到回车就停止读取
    while (getline(cin, line))  // 回车虽然被读到了，但是被丢弃
        cout << line << endl;
}




int main(int argc, const char * argv[]) {
    readStringUtilCarriage();
    
    return 0;
}
