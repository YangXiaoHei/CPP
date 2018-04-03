//
//  Sales_data.hpp
//  Learning
//
//  Created by YangHan on 2018/4/3.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#ifndef Sales_data_hpp
#define Sales_data_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

struct Sales_data {
    string isbn() const { return bookNo; }
    Sales_data & combine(const Sales_data &);
    double avg_price() const;
    
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
ostream& print(ostream&, const Sales_data&);
istream& read(istream&, Sales_data&);

#endif /* Sales_data_hpp */
