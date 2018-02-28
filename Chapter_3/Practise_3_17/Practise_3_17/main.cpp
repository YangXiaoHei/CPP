//
//  main.cpp
//  Practise_3_17
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<string> words;
    string word;
    while (cin >> word) {
        for (auto &c : word)
            c = toupper(c);
        words.push_back(word);
    }
    for (auto word : words)
        cout << word << endl;
        
    return 0;
}
