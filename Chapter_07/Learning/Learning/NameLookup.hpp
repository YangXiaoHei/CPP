//
//  NameLookup.hpp
//  Learning
//
//  Created by YangHan on 2018/4/3.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#ifndef NameLookup_hpp
#define NameLookup_hpp

#include <stdio.h>
#include <string>

namespace YH_3 {
    typedef double Money;
    class Account {
        typedef char * Money;
    public:
        Money balance() { return bal; }
    private:
        Money bal;
    };
}

namespace YH_2 {
//    typedef double  Money;
//    class Account {
//    public:
//        Money balance() { return bal; }
//    private:
//        typedef char * Money;
//        Money bal;
//    };
}

/**
 *  编译器直接报错
 */
namespace YH_1 {
    typedef double  Money;
    std::string bal;
    class Account {
    public:
        Money balance() { return bal; }
    private:
        Money bal;
    };
}







#endif /* NameLookup_hpp */
