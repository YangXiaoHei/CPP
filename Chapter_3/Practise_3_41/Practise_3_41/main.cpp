//
//  main.cpp
//  Practise_3_41
//
//  Created by YangHan on 2018/3/2.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int a[] = {1, 3, 5, 7, 9, 11, 13};
    
    vector<int> iv(begin(a), end(a));
    for (int i = 0; i < iv.size(); i++) {
        cout << iv[i] << endl;
    }
    
    
    
    return 0;
}
