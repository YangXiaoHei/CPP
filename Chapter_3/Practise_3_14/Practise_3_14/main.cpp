//
//  main.cpp
//  Practise_3_14
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<int> ivec;
    int i;
    while (cin >> i)
        ivec.push_back(i);
    
    cout << ivec.size() << endl;
    
    return 0;
}
