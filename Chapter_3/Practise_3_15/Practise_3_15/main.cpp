//
//  main.cpp
//  Practise_3_15
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string word; vector<string> words;
    while (cin >> word)
        words.push_back(word);
    
    cout << words.size() << endl;
    
    return 0;
}
