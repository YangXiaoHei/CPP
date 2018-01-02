//
//  main.cpp
//  Practise_1_12
//
//  Created by YangHan on 2018/1/2.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    /**
     *  最终结果是 0
     */
    int sum = 0;
    for (int i = -100; i <= 100; ++i)
        sum += i;
    printf("%d\n", sum);
    
    return 0;
}
// output
/**
 *  0
 */
