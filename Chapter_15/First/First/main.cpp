//
//  main.cpp
//  First
//
//  Created by YangHan on 2018/4/18.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <string>
#include <istream>
#include <fstream>

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
        virtual ostream& debug() const;
        
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
        
        ostream& debug() const override;
        
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
    
    ostream& Quote::debug() const
    {
        return cout << bookNo << " ";
    }
    
    ostream& Bulk_Quote::debug() const
    {
        return Quote::debug() << price << " "
                              << min_qty << " " << discount;
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
            return nMax * (1 - discount) * price + (n - nMax) * price;
        }
    }
    
    void test()
    {
        Limit_Quote a("C++ Primer", 3, 10, 0.5);
        a.show(10);
        a.show(9);
    }
}


namespace Practise_15_08 {
    void test()
    {
        /**
         *  静态类型 ： 在编译期决定的类型
            动态类型 ： 在运行时决定的类型
         */
    }
}

namespace Practise_15_09 {
    struct Programmer {};
    struct Cpp : public Programmer {};
    struct iOS : public Programmer {};
    
    void test1(Programmer& p)
    {
        
    }
    void test2()
    {
        Cpp cpp;
        Programmer *p = &cpp;
    }
    void test()
    {
        iOS ios;
        test1(ios);
    }
}

namespace Practise_15_10 {
    void test()
    {
        /**
         *  input 是一个 ifstream 对象，而 ifstream 继承自 istream
            read 接受一个  istream& 对象，因此发生了动态绑定，调用了 input 的具体实现
         */
    }
}

/**
 *  Override
 */
namespace YH4 {
    struct A
    {
        virtual void f1(int) const;
        virtual void f2();
        void f3();
    };
    struct B : public A
    {
        void f1(int) const override {}
//        void f2(int) override {}
//        void f3() override {}
//        void f4() override {}
    };
    void test()
    {
        
    }
}

/**
 *  Final
 */
namespace YH5 {
    struct A
    {
        virtual void f2();
        virtual void f1(int) const final;
    };
    struct B : public A
    {
        void f2() {}
//        void f1(int) const {}
    };
    void test()
    {
        
    }
}

/**
 *  回避虚函数机制
 */
namespace YH6 {
    struct A
    {
        virtual void f() const {
            cout << "初始化" << endl;
        }
    };
    struct B : public A
    {
        void f() const
        {
            // 使用作用域运算符指定调用方法的版本
            A::f();
            cout << "hello world" << endl;
        }
    };
    void test1(const A &a)
    {
        a.f();
    }
    void test()
    {
        B b;
        test1(b);
    }
}


namespace Practise_15_11 {
    using namespace Practise_15_07;
    void test1(Quote& q)
    {
        q.debug() << endl;
    }
    void test()
    {
        Bulk_Quote bq("C++ Primer", 3, 10, 0.8);
        Limit_Quote lq("Algorithms", 4, 5, 0.7);
        test1(bq);
        test1(lq);
    }
}

namespace Practise_15_12 {
    void test()
    {
        /**
         *  有必要啊，代表该函数是覆盖父类的虚函数，并且不允许被子类继续覆盖
         */
    }
}

namespace Practise_15_13 {
    class base
    {
    public:
        string name() { return basename; }
        virtual void print(ostream &os) { os << basename; }
    private:
        string basename;
    };
    class derived : public base
    {
    public:
        void print(ostream &os) { print(os);  os << " " << i; }
    private:
        int i;
    };
    void test()
    {
        /**
         *  在派生类的 print 实现中，这里本意想先调用父类实现，但却造成死循环，应该使用作用域运算符限定调用父类方法
         */
    }
}

namespace Practise_15_14 {
    void test()
    {
        /**
         *  a 父类
            b 子类
            c 父类
            d 子类
            e 父类
            f 子类
         */
    }
}

namespace Practise_15_15 {
    class Quote
    {
    public:
        Quote() = default;
        Quote(const string &b, double p) : bookNo(b), price(p) {}
        
        virtual const string& isbn() const;
        virtual double net_price(size_t n) const;
        
        virtual ~Quote() = default;
        
    protected:
        double price = 0;
    private:
        string bookNo;
    };
    
    class Disc_quote : public Quote
    {
    public:
        Disc_quote() = default;
        Disc_quote(const string &book, double p, size_t qty, double disc) :
        Quote(book, p), quantity(qty), discount(disc) {}
        
        virtual double net_price(size_t) const = 0;
        
    protected:
        size_t quantity = 0;
        double discount = 0.0;
    };
    
    class Bulk_quote : public Disc_quote
    {
    public:
        Bulk_quote() = default;
        Bulk_quote(const string &book, double p, size_t qty, double disc) :
        Disc_quote(book, p, qty, disc) {}
        
        double net_price(size_t) const override;
    };
    
    class Limit_quote : public Disc_quote
    {
    public:
        Limit_quote() = default;
        Limit_quote(const string &book, double p, size_t qty, double disc) :
        Disc_quote(book, p, qty, disc) {}
        
        double net_price(size_t) const override;
    };
    
    double Bulk_quote::net_price(size_t n) const
    {
        if (n < quantity)
        {
            return n * price;
        }
        else
        {
            return n * (1 - discount) * price;
        }
    }
    
    double Limit_quote::net_price(size_t n) const
    {
        if (n < quantity)
        {
            return n * (1 - discount) * price;
        }
        else
        {
            return quantity * (1 - discount) * price + (n - quantity) * price;
        }
    }
    
    void test()
    {
        
    }
}

namespace Practise_15_16 {
    void test()
    {
        /**
         *  见 Practise_15_15
         */
    }
}

namespace Practise_15_17 {
    void test()
    {
        using namespace Practise_15_15;
        
//        Disc_quote dis;
    }
}

namespace Practise_15_18 {
    class Base
    {
    protected:
        int prot_mem;
    };
    class Sneaky : public Base
    {
        friend void clobber(Sneaky &);
        friend void clobber(Base &);
        int j;
    };
    
    /**
     *  派生类的成员或友元只能通过派生类对象来访问基类的受保护成员。
     */
    void clobber(Sneaky &s)
    {
        s.j = s.prot_mem = 0;
    }
    
    void clobber(Base &b)
    {
//        b.prot_mem = 0; ❌
    }
    
    void test()
    {
        
    }
}

namespace Practise_15_19 {
    class Base
    {
    public:
        void pub_mem();
    protected:
        int prot_mem;
    private:
        char priv_mem;
    };
    struct Pub_Derv : public Base
    {
        int f() { return prot_mem; }
        
//        char g() { return priv_mem; } //❌
    };
    struct Priv_Derv : private Base
    {
        int f1() const
        {
            // private 不影响派生类的访问权限
            // 派生访问说明符的目的是控制派生类用户（包括派生类的派生类在内）对于基类成员的访问权限
            return prot_mem;
        }
    };
    void test()
    {
        Pub_Derv d1;
        Priv_Derv d2;
        d1.pub_mem();
//        d2.pub_mem(); // ❌
    }
}






int main(int argc, const char * argv[]) {
    Practise_15_11::test();
    return 0;
}
