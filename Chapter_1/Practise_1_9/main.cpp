//
//  main.cpp
//  Practise_1_9
//
//  Created by YangHan on 2018/1/1.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int sum = 0, i = 50;
    while (i <= 100) sum += i++;
    cout << "结果为 : " << sum << endl;
    
    return 0;
}
