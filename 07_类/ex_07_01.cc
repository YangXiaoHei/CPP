#include <iostream>
#include <string>

using namespace std;

struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    string isbn() const { return bookNo;  }
    Sales_data &combine(const Sales_data &);
    double avg_price() const;
};

Sales_data & Sales_data::combine(const Sales_data &rhs)
{
    if (rhs.bookNo != bookNo) 
    {
        cout << "bookNo must be same" << endl;
        return *this;
    }
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data add(const Sales_data &a, const Sales_data &b)
{
    Sales_data s;
    if (a.bookNo != b.bookNo)
    {
        cout << "bookNo must be same" << endl;
        return s;
    }
    s.units_sold = a.units_sold + b.units_sold;
    s.revenue = a.revenue + b.revenue;
    s.bookNo = a.bookNo;
    return s; 
}
ostream &print(ostream &os, const Sales_data &a)
{
    os << a.bookNo << " : " << a.units_sold << " " << a.revenue << endl;
    return os;
}
istream &read(istream &is, Sales_data &a)
{
    is >> a.bookNo >> a.units_sold >> a.revenue; 
    return is;
}

int main()
{
    Sales_data a;
    read(cin, a);
    print(cout, a);
    Sales_data b;
    read(cin, b);
    print(cout, b);

    Sales_data c = add(a, b);
    print(cout, c);
}
