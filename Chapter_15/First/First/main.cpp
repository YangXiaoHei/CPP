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
#include <math.h>
#include <vector>

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
    
    const string& Quote::isbn() const
    {
        return bookNo;
    }
    
    double Quote::net_price(size_t n) const
    {
        return n * price;
    }
    
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

namespace XXX {
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

namespace XXX1 {
    class Base
    {
    public:
        void pub_mem() {};
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
    
    struct Derived_from_Public : public Pub_Derv
    {
        int use_base() { return prot_mem; }
    };
    struct Derived_from_Private : public Priv_Derv
    {
//        int use_base() { return prot_mem; } // ❌
    };
    
    void test()
    {
        Pub_Derv d1;
        Priv_Derv d2;
        d1.pub_mem();
//        d2.pub_mem(); // ❌
    }
}

namespace YH7 {
    struct A
    {
        
    };
    struct B : public A
    {
        
    };
    struct C : private A
    {
        
    };
    void test()
    {
        B b; C c;
        A *pa = &b;
//        pa = &c;  私有继承，不能向基类转换  // ❌
    }
}

namespace YH8 {
    class Friend
    {
        void f0();
    };
    /**
     *  不论 D 以什么方式继承 B，D 的成员函数和友元都能使用派生类向基类的转换
        派生类向基类的类型转换对于派生类的成员和友元来说永远是可访问的
     */
    struct A
    {
        
    };
    struct B : private A
    {
        friend class Friend;
        friend void f1();
        void f2();
    };
    
    //友元类
    void Friend::f0()
    {
        B b;
        A *pa = &b;
    }
    
    // 友元函数
     void f1()
    {
        B b;
        A *pa = &b;
    }
    
    // 成员函数
    void B::f2()
    {
        B b;
        A *pa = &b;
    }
    
    void test()
    {
        
    }
}

namespace YH9 {
    struct A
    {
        
    };
    class Friend
    {
        void f0();
    };
    struct B : private A
    {
        
    };
    struct C : public B
    {
        friend class Friend;
        friend void f1();
        void f2();
    };
    
    //友元类
    void Friend::f0()
    {
        B b;
//        A *pa = &b; // ❌
    }
    
    // 友元函数
    void f1()
    {
        B b;
//        A *pa = &b;  // ❌
    }
    
    // 成员函数
    void C::f2()
    {
        B b;
//        A *pa = &b; // ❌
    }
    void test()
    {
        C c;
        B *p = &c;
    }
}

namespace YH10 {
    class Base
    {
        friend class Pal;
    public:
        void pub_mem() {};
    protected:
        int prot_mem;
    private:
        char priv_mem;
    };
    class Sneaky : public Base
    {
        friend void clobber(Sneaky&);
        friend void clobber(Base&);
        int j;
    };
    class Pal
    {
    public:
        int f(Base b) { return b.prot_mem; }
//        int f2(Sneaky s) { return s.j; } //❌ Pal 不是 Sneaky 的友元
        int f3(Sneaky s) { return s.prot_mem; } // 正确 Pal 是 Base 的友元
    };
    class D2 : public Pal
    {
    public:
        int mem(Base b)
        {
//            return b.prot_mem;  // ❌ 友元关系不能继承
            return 1;
        }
    };
    void test()
    {
        
    }
}

/**
 *  改变个别成员的可访问性
 */
namespace YH11 {
    class Base
    {
    public:
        size_t size() const { return n; }
    protected:
        size_t n;
    };
    class Derived : private Base
    {
    public:
        using Base::size;
    protected:
        using Base::n;
    };
    void test()
    {
        Derived d;
        cout << d.size() << endl;
    }
}

/**
 *  默认的继承保护级别
 */
namespace YH12  {
    class Base {};
    struct D1 : Base {}; // 默认公有继承
    class D2 : Base {};  // 默认私有继承
    void test()
    {
        
    }
}

namespace Practise_15_18 {
    class Base {};
    
    class Pub_Derv : public Base {};
    class Pro_Derv : protected Base {};
    class Pri_Derv : private Base {};
    
    class Dervied_from_Public : public Pub_Derv {};
    class Dervied_from_Protected : protected Pro_Derv {};
    class Dervied_from_Private : private Pri_Derv {};
    void test()
    {
        Pub_Derv d1;
        Pri_Derv d2;
        Pro_Derv d3;
        Dervied_from_Public dd1;
        Dervied_from_Private dd2;
        Dervied_from_Protected dd3;
        
          Base *p = &d1;   // 不管如何继承,派生类都能访问基类的公有成员，所以能转成基类指针
//                p = &d2;   // ❌
//                p = &d3;   // ❌
                p = &dd1;
//                p = &dd2;  // ❌
//                p = &dd3;  // ❌
        
    }
}

namespace Practise_15_19 {
    class Base
    {
    };
    class Pub_Derv : public Base {
        void memfcn(Base &b) { b = *this; }
    };
    class Pro_Derv : protected Base {
        void memfcn(Base &b) { b = *this; }
    };
    class Pri_Derv : private Base {
        void memfcn(Base &b) { b = *this; }
    };
    class Dervied_from_Public : public Pub_Derv {
        void memfcn(Base &b) { b = *this; }
    };
    class Dervied_from_Protected : protected Pro_Derv {
        void memfcn(Base &b) { b = *this; }
    };
    class Dervied_from_Private : private Pri_Derv {
//        void memfcn(Base &b) { b = *this; }  // ❌
    };
    
    void test()
    {
        
    }
}

namespace Practise_15_20 {
    void test()
    {
        /**
         *  见 Practise_15_19、18
         */
    }
}

namespace Practise_15_21 {
    class Graph
    {
        
    };
    class Rectangle : public Graph
    {
        
    };
    class Circle : public Graph
    {
        
    };
    class Triangle : public Graph
    {
        
    };
    void test()
    {
        
    }
}

namespace Practise_15_22 {
    class Graph
    {
    public:
        Graph(const string& n) : shape_name(n) {}
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual const string& name() const;
    private:
        string shape_name;
    };
    const string& Graph::name() const
    {
        return shape_name;
    }
    
    class Rectangle : public Graph
    {
    public:
        Rectangle(const string& n, double w, double h) : Graph(n), w_(w), h_(h) {}
        double area() const override;
        double perimeter() const override;
    private:
        double w_;
        double h_;
    };
    double Rectangle::area() const
    {
        return w_ * h_;
    }
    double Rectangle::perimeter() const
    {
        return (w_ + h_) * 2;
    }
    
    class Circle : public Graph
    {
    public:
        Circle(const string& n, double r) : Graph(n), radius_(r) {}
        double area() const override;
        double perimeter() const override;
    protected:
        static double PI;
    private:
        double radius_;
    };
    double Circle::PI = 3.1415926;
    double Circle::area() const
    {
        return PI * radius_ * radius_;
    }
    double Circle::perimeter() const
    {
        return 2 * PI * radius_;
    }
    
    class RightTriangle : public Graph
    {
    public:
        RightTriangle(const string& n, double l1, double l2) : Graph(n), l1_(l1), l2_(l2) {}
        double area() const override;
        double perimeter() const override;
    private:
        double l1_;
        double l2_;
    };
    double RightTriangle::area() const
    {
        return l1_ * l2_ * 0.5;
    }
    double RightTriangle::perimeter() const
    {
        return l1_ + l2_ + sqrt(l1_ * l1_ + l2_ * l2_);
    }
    
    void test()
    {
        
    }
}

namespace YH13 {
    struct Base
    {
        Base() : mem(0) {}
    protected:
        int mem;
    };
    /**
     *  如果派生类重用基类中的名字，那么会隐藏基类的
     */
    struct Derived : Base
    {
        Derived(int i) : mem(i) {}
        int get_mem() { return mem; }
        
        int get_base_mem() { return Base::mem; }
    protected:
        int mem;
    };
    void test()
    {
        Derived d(42);
        cout << d.get_mem() << endl;
    }
}

namespace YH14 {
    struct Base
    {
        int memfcn() { return 1; };
    };
    struct Derived : Base
    {
        int memfcn(int i) { return 1; }
    };
    void test()
    {
        Derived d; Base b;
        b.memfcn();
        d.memfcn(10);
//        d.memfcn();  // 基类中的 memfcn() 被隐藏了
        d.Base::memfcn();
    }
}

namespace YH15 {
    class Base
    {
    public:
        virtual int fcn();
    };
    class D1 : public Base
    {
    public:
        int fcn(int);
        virtual void f2();
    };
    class D2 : public D1
    {
    public:
        int fcn(int i) { return 1; }
        int fcn() { return 1; }
        void f2() {}
    };
    void test()
    {
        
    }
}

namespace Practise_15_23 {
    class Base
    {
    public:
        virtual int fcn() { cout << "Base::fcn()" << endl; return 1; }
    };
    class D1 : public Base
    {
    public:
        int fcn() { cout << "D1::fcn()" << endl; return 1; }
        virtual void f2() { cout << "D1::f2()" << endl; }
    };
    class D2 : public D1
    {
    public:
        int fcn(int i) { cout << "D2:fcn(int)" << endl; return 1; }
        int fcn() { cout << "D2::fcn()" << endl;  return 1; }
        void f2() { cout << "D2::f2()" << endl; }
    };
    void test()
    {
        
    }
}

namespace Practise_15_24 {
    void test()
    {
        /**
         *  通常情况下，一个基类应该定义一个虚析构函数
            析构函数应该定义成虚的，以便可以在 delete 基类指针时，也可以正确释放子类重写的析构函数
         */
    }
}

namespace YH16 {
    void test()
    {
        /**
         * 1、如果定义了拷贝构造、拷贝赋值运算符、析构函数中的一个，那么编译器不会自动合成移动构造和移动赋值运算符
           2、定义了移动构造和移动赋值运算符后，也必须定义拷贝构造和拷贝赋值运算符，以及析构函数
           3、只有当类中所有成员都可以移动，并且没有定义拷贝控制其他成员，编译器才会合成移动构造和移动赋值运算符
         */
    }
}

namespace Practise_15_25 {
    void test()
    {
        /**
         *  因为 Disc_quote 定义了自己的构造函数，假如不为 Dics_quote 定义一个默认的构造函数，
            那么默认构造函数是删除的，所以继承自 Disc_quote 的所有类的默认构造函数都是删除的，也就是说
            所有继承自 Disc_quote 的派生类都不能使用默认构造函数的初始化
         */
    }
}

namespace Practise_15_26 {
    class Quote
    {
    public:
        Quote() { cout << "Quote 默认构造" << endl; }
        Quote(const string& b, double p) : bookNo(b), price(p) { cout << "Quote 参数构造" << endl;}
        
        virtual const string& isbn() const;
        virtual double net_price(size_t n) const;
        
        virtual ~Quote() { cout << "Quote 析构" << endl; }
    protected:
        double price;
    private:
        string bookNo;
    };
    const string& Quote::isbn() const
    {
        return bookNo;
    }
    double Quote::net_price(size_t n) const
    {
        return n * price;
    }
    
    
    class Disc_quote : public Quote
    {
    public:
        Disc_quote() { cout << "Disc_quote 默认构造" << endl; }
        Disc_quote(const string& b, double p, size_t qty, double disc) : Quote(b, p), quantity(qty), discount(disc) { cout << "Disc_quote 参数构造" << endl; }
        
        virtual double net_price(size_t n) const = 0;
        
        ~Disc_quote() { cout << "Disc_quote 析构" << endl; }
    protected:
        size_t quantity;
        double discount;
    };
    
    class Bulk_quote : public Disc_quote
    {
    public:
        using Disc_quote::Disc_quote;
//        Bulk_quote() { cout << "Bulk_quote 默认构造" << endl; }
//        Bulk_quote(const string& b, double p, size_t n, double d) : Disc_quote(b, p, n, d) { cout << "Bulk_quote 参数构造" << endl; }
        
        double net_price(size_t n) const override;
        
        ~Bulk_quote() { cout << "Bulk_quote 析构" << endl; }
    };
    double Bulk_quote::net_price(size_t n) const
    {
        if (n < quantity)
        {
            return n * price;
        }
        else
        {
            return quantity * price + (n - quantity) * (1 - discount) * price;
        }
    }
    
    class Limit_quote : public Disc_quote
    {
    public:
//        Limit_quote() { cout << "Limit_quote 默认构造" << endl; }
//        Limit_quote(const string& b, double p, size_t n, double d) : Disc_quote(b, p, n, d) { cout << "Limit_quote 参数构造" << endl; }
        using Disc_quote::Disc_quote;
        
        double net_price(size_t n) const override;
        
        ~Limit_quote() { cout << "Limit_quote 析构" << endl; }
    };
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
//        Bulk_quote b;
//        Limit_quote l;
        Bulk_quote b("C++Primer", 10.3, 5, 0.5);
        Limit_quote l("Algorithms4", 20.4, 8, 0.75);
    }
}

namespace YH17 {
    class A
    {
    public:
        A() { cout << " A" << endl; }
    };
    class B : public A
    {
        
    };
    void test()
    {
        B b;
    }
}

namespace Practise_15_27 {
    void test()
    {
        /**
         *  见Practise_15_26
         */
    }
}

namespace Practise_15_28 {
    class Quote
    {
    public:
        Quote() = default;
        Quote(const string& b, double p) : bookNo(b), price(p) {}
        
        virtual const string& isbn() const;
        virtual double net_price(size_t n) const;
        
        virtual ~Quote() = default;
    protected:
        double price;
    private:
        string bookNo;
    };
    const string& Quote::isbn() const
    {
        return bookNo;
    }
    double Quote::net_price(size_t n) const
    {
        return n * price;
    }
    
    
    class Disc_quote : public Quote
    {
    public:
        Disc_quote() {}
        Disc_quote(const string& b, double p, size_t qty, double disc) : Quote(b, p), quantity(qty), discount(disc) {}
        
        virtual double net_price(size_t n) const = 0;
    protected:
        size_t quantity;
        double discount;
    };
    
    class Bulk_quote : public Disc_quote
    {
    public:
        using Disc_quote::Disc_quote;
        double net_price(size_t n) const override;
    };
    double Bulk_quote::net_price(size_t n) const
    {
        if (n < quantity)
        {
            return n * price;
        }
        else
        {
            return quantity * price + (n - quantity) * (1 - discount) * price;
        }
    }
    
    class Limit_quote : public Disc_quote
    {
    public:
        using Disc_quote::Disc_quote;
        double net_price(size_t n) const override;
    };
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
        vector<Quote> v;
        Bulk_quote b("C++ Primer", 10, 5, 0.75);
        v.push_back(b);
        cout << v.back().net_price(10) << endl;
    }
}


int main(int argc, const char * argv[]) {
    Practise_15_28::test();
    return 0;
}
