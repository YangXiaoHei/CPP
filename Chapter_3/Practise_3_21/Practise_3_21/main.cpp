//
//  main.cpp
//  Practise_3_21
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void display(const vector<int> &v) {
    cout << "尺寸 : " << v.size() << endl;
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n\n";
}

void display(const vector<string> &v) {
    cout << "尺寸 : " << v.size() << endl;
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n\n";
}

int main(int argc, const char * argv[]) {
    
    // a
    {
        vector<int> v1;
        display(v1);
    }
    // b
    {
        vector<int> v2(10);
        display(v2);
    }
    // c
    {
        vector<int> v3(10, 42);
        display(v3);
    }
    // d
    {
        vector<int> v4{10};
        display(v4);
    }
    // e
    {
        vector<int> v5{10, 42};
        display(v5);
    }
    // f
    {
        vector<string> v6{10};
        display(v6);
    }
    // g
    {
        vector<string> v7{10, "hi"};
        display(v7);
    }
    
    return 0;
}
