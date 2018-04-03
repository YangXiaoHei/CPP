//
//  Constructor.hpp
//  Learning
//
//  Created by YangHan on 2018/4/3.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#ifndef Constructor_hpp
#define Constructor_hpp

#include <stdio.h>
#include <string>
#include <iostream>

class Constructor {
public:
    /**
     *  二义性，不合法
     */
    Constructor(std::istream& is = std::cin);
    Constructor(std::string s = "");
private:
    std::string s;
};



#endif /* Constructor_hpp */
