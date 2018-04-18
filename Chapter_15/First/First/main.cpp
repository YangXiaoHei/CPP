//
//  main.cpp
//  First
//
//  Created by YangHan on 2018/4/18.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

namespace YH {
    class Quote
    {
    public:
        Quote(const string& s = string()) : bookNo(s) {}
        string isbn() const;
        virtual double net_price(size_t n) const;
    protected:
        string bookNo;
    };
    
    class Bulk_quote : public Quote
    {
    public:
        Bulk_quote(const string& s = string()) {
          
        }
        double net_price(size_t n) const override;
    };
    
    string Quote::isbn() const
    {
        return bookNo;
    }
    
    double Quote::net_price(size_t n) const
    {
        return n * 10;
    }
    
    double Bulk_quote::net_price(size_t n) const
    {
        return n * 30;
    }
    
    double print_total(ostream& os, const Quote &item, size_t n)
    {
        double ret = item.net_price(n);
        os << "ISBN: " << item.isbn() << " # sold "
        << n << " total due: " << ret << endl;
        return ret;
    }
    void test()
    {
        Quote a("yanghan");
        Bulk_quote b("xixi");
        print_total(cout, a, 20);
        print_total(cout, b, 20);
    }
}

namespace YH1 {
    class Quote
    {
    public:
        Quote() = default;
        Quote(const string &book, double sales_price) : bookNo(book), price(sales_price){}
        string isbn() const { return bookNo; }
        virtual double net_price(size_t n) const { return n * price; }
        /**
         *  基类通常应该定义一个虚析构函数，即使该函数不执行任何实际操作也是如此
         */
        virtual ~Quote() = default;
    private:
        string bookNo;
    protected:
        double price = 0.0;
    };
}

namespace Practise_15_01 {
    void test() {
        /**
         *  虚成员就是当使用基类指针调用时会发生动态绑定的成员
            虚成员用于实现多态
         */
    }
}

namespace Practise_15_02 {
    void test() {
        /**
         *  protected 用以说明需要派生类有权访问而禁止其他用户访问
            private 说明只有当前类可以访问，其他任何类即使是派生类也无权访问
         */
    }
}

namespace Practise_15_03 {
    class Quote
    {
    public:
        Quote() = default;
        Quote(const string &b, double p) : bookNo(b), price(p) {}
        
        virtual string isbn() const;
        virtual double net_price(size_t n) const;
        
        virtual ~Quote() = default;
    private:
        string bookNo;
    protected:
        double price = 0.0;
    };
}

namespace YH2 {
    using Practise_15_03::Quote;
    class Bulk_Quote : public Quote
    {
    public:
        Bulk_Quote() = default;
        Bulk_Quote(const string&, double, size_t, double);
        double net_price(size_t) const override;
    private:
        size_t min_qty = 0;
        double discount = 0.0;
    };
    void test()
    {
        
    }
}

namespace YH3 {
    void test()
    {
        /**
         *  派生类和基类分别控制自己的构造过程
         
            派生类可以在自己的初始化列表中调用父类构造函数
         
         静态成员
             Father::staticMem()
             Child::staticMem()
             ChildObj.staticMem()
             staticMem()  通过 this 访问
         
          final 防止继承发生
         */
    }
}

namespace Practise_15_04 {
    void test()
    {
        /**
         *  a, 不对，不能自己派生自己
            b, 可以
            c, 不对，声明不能加派生列表
         */
    }
}

namespace Practise_15_05 {
    class Quote
    {
    public:
        Quote() = default;
        Quote(const string& b, double p) : bookNo(b), price(p) {}
        
        virtual const string& isbn() const;
        virtual double net_price(size_t n) const;
        
        virtual void show(size_t n) const;
        
        virtual ~Quote() = default;
    private:
        string bookNo;
    protected:
        double price = 0.0;
    };
    
    class Bulk_Quote : public Quote
    {
    public:
        Bulk_Quote() = default;
        Bulk_Quote(const string &b, double p, size_t qty, double disc) :
                    Quote(b, p), min_qty(qty), discount(disc) {}
        
        double net_price(size_t n) const override;
    private:
        size_t min_qty;
        double discount = 0.0;
    };
    
    void Quote::show(size_t n) const
    {
        cout << isbn() << " : " << n << " 本 " << net_price(n) << " 元" << endl;
    }
    
    double Quote::net_price(size_t n) const
    {
        return n * price;
    }
    
    const string& Quote::isbn() const
    {
        return bookNo;
    }
    
    double Bulk_Quote::net_price(size_t n) const
    {
        if (n > min_qty)
        {
            return n * (1 - discount) * price;
        }
        else
        {
            return n * price;
        }
    }
    
    
    void test()
    {
        Quote a("C++ Primer", 3);
        Bulk_Quote b("Algorithms", 3, 5, 0.5);
        
        a.show(10);
        b.show(10);
    }
}

namespace Practise_15_06 {
    void test()
    {
        /**
         *  见 Practise_15_05
         */
    }
}

namespace Practise_15_07 {
    using Practise_15_05::Quote;
    using Practise_15_05::Bulk_Quote;
    
    class Limit_Quote : public Quote
    {
    public:
        Limit_Quote() = default;
        Limit_Quote(const string& b, double p, size_t max, double disc) :
        Quote(b, p), nMax(max), discount(disc) {}
        
        double net_price(size_t n) const override;
        
    private:
        size_t nMax = 0;
        double discount = 0.0;
    };
    
    double Limit_Quote::net_price(size_t n) const
    {
        if (n < nMax)
        {
            return n * (1 - discount) * price;
        }
        else
        {
            return n * price;
        }
    }
    
    void test()
    {
        Limit_Quote a("C++ Primer", 3, 10, 0.5);
        a.show(10);
        a.show(9);
    }
}



int main(int argc, const char * argv[]) {
    Practise_15_07::test();
    return 0;
}
