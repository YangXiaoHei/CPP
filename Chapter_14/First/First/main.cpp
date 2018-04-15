//
//  main.cpp
//  First
//
//  Created by YangHan on 2018/4/15.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

using namespace std;

namespace Practise_14_01 {
    void test() {
        /**
            不同
            1、对于重载的运算符，可以通过 operatorX(a, b) 来调用
            2、重载函数要么是个成员函数，要么至少有一个类类型参数
            3、部分运算符比如逻辑与逻辑或的短路属性不能被重载后函数继承
         
            相同
            优先级相同
         */
    }
}

namespace Practise_14_02 {
    class Sales_data {
        friend ostream& operator<<(ostream &os, const Sales_data& s) {
            os << s.bookNo << " : " << s.units_sold << " " << s.revenue;
            return os;
        }
        friend istream& operator>>(istream& is, Sales_data& s) {
            is >> s.bookNo >> s.units_sold >> s.revenue;
            return is;
        }
        friend Sales_data operator+(const Sales_data &a, const Sales_data &b) {
            Sales_data sum;
            sum.units_sold = a.units_sold + b.units_sold;
            sum.revenue = a.revenue + b.revenue;
            sum.bookNo = a.bookNo;
            return sum;
        }
    public:
        Sales_data() :
                units_sold(0), revenue(0.0) {}
        Sales_data(const string &s) :
                units_sold(0), revenue(0.0), bookNo(s) {}
        Sales_data(const string &s, unsigned u, double r) :
                bookNo(s), units_sold(u), revenue(r) {}
        Sales_data(const Sales_data &s) = default;
        Sales_data(Sales_data &&s) noexcept :
                bookNo(std::move(s.bookNo)), units_sold(s.units_sold), revenue(s.revenue)  {
                    s.units_sold = 0;
                    s.revenue = 0.0;
                }
        Sales_data& operator=(Sales_data &&s) {
            if (this != &s) {
                bookNo = std::move(s.bookNo);
                units_sold = s.units_sold;
                revenue = s.revenue;
                s.units_sold = 0;
                s.revenue = 0.0;
            }
            return *this;
        }
        Sales_data& operator+=(const Sales_data &s) {
            revenue += s.revenue;
            units_sold += s.units_sold;
            return *this;
        }
        string isbn() const { return bookNo; }
    private:
        string bookNo;
        unsigned units_sold;
        double revenue;
    };
    void test() {
        
        Sales_data a, b;
        cout << "请输入 a" << endl;
        cin >> a;
        cout << "请输入 b" << endl;
        cin >> b;
        cout << "输入的 a 为 :" << endl;
        cout << a << endl;
        cout << "输入的 b 为 :" << endl;
        cout << b << endl;
        cout << "a + b 为 :" << endl;
        cout << a + b << endl;
   
    }
}


int main(int argc, const char * argv[]) {

    Practise_14_02::test();
    
    return 0;
}
