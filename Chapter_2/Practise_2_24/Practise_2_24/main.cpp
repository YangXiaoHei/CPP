//
//  main.cpp
//  Practise_2_24
//
//  Created by YangHan on 2018/2/27.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int i = 42;
    
    void *p = &i;
    
    /**
     *  p 不用关心存放的对象是什么类型
     
        如果可以用 long 指向存放 int 对象的空间，那么解引用会取到 8 个字节
     */
    
//    long *lp = &i; 类型不匹配
    
    
    return 0;
}
