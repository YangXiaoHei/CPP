//
//  Sales_data.cpp
//  Learning
//
//  Created by YangHan on 2018/4/3.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include "Sales_data.hpp"

Sales_data& Sales_data::combine(const Sales_data &a) {
    units_sold += a.units_sold;
    revenue += a.revenue;
    return *this;
}

double Sales_data::avg_price() const {
    return revenue / units_sold;
}

Sales_data add(const Sales_data& a, const Sales_data& b) {
    Sales_data c;
    c.revenue = a.revenue + b.revenue;
    c.units_sold = a.units_sold + b.units_sold;
    c.bookNo = a.bookNo + b.bookNo;
    return c;
}

ostream& print(ostream& os, const Sales_data& a) {
   return os << a.bookNo << " " << a.units_sold << " " << a.revenue << endl;
}

istream& read(istream& is, Sales_data& a) {
    return is >> a.bookNo >> a.units_sold >> a.revenue;
}





