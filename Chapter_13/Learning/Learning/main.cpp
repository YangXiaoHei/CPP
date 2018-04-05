//
//  main.cpp
//  Learning
//
//  Created by YangHan on 2018/4/5.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

namespace YH1 {
    class A {
    public:
        A() {
            cout << "A constructor" << endl;
        }
        A(const A& a) {
            cout << "A copy constructor" << endl;
        }
    };
    /**
     *  拷贝初始化的发生场景
     *  1，把对象作为实参传递给非引用型的形参
        2，从一个返回类型为非引用类型的函数返回一个对象
        3，用花括号列表初始化一个数组中的元素或一个聚合类中的成员
     
        如果是 gcc/clang 编译器，要加上编译器选项 -fno-elide-constructors 才可以看到
     */
    void test(A a) {
        cout << "test" << endl;
    }
    A test2() {
        return A();
    }
    void test3() {
        A a[] = { A(), A(), A() };
    }
    
    class Point {
    public:
        Point() {
            cout << "Point()" << endl;
        }
        Point(const Point &p) {
            cout << "Point copy()" << endl;
        }
        Point& operator=(const Point &p) {
            cout << "Point equal()" << endl;
            return *this;
        }
        
    };
    Point global;
    Point foo_bar(Point arg) {
        cout << "0" << endl;
        Point local = arg;
        cout << "1" << endl;
        
        Point *heap = new Point( global );
        cout << "2" << endl;
        
        *heap = local;
        cout << "3" << endl;
        
        Point pa[4] = { local, *heap };
        cout << "4" << endl;
        
        return *heap;
    }
    
    class HasPtr {
    public:
        HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
        HasPtr(const HasPtr &hp) {
            ps = new string(*hp.ps);
            i = hp.i;
            cout << "HasPtr copy()" << endl;
        }
        long saddr() {
            return (long)ps;
        }
    private:
        string *ps;
        int i;
    };
}


namespace YH2 {
    /**
     *  析构函数发生的场景
     *  1，变量离开其作用域时被销毁
        2，当一个对象被销毁，其成员被销毁
        3，容器（无论是标准库还是数组）被销毁时，其元素被销毁
        4、动态分配的对象，对指向他的指针使用 delete 时被销毁
        5、临时对象，当创建它的完整表达时结束时被销毁
     */
    class A {
    public:
        A() {
            cout << "A create" << endl;
        }
        A(const A& a) {
            cout << "A copy" << endl;
        }
        ~A() {
            cout << "A dealloc" << endl;
        }
    };
    
    class B {
    public:
        A a;
        B() {
            cout << "B create" << endl;
        }
        B(const B& b) {
            cout << "B copy" << endl;
        }
        ~B() {
            cout << "B dealloc" << endl;
        }
    };
}

namespace YH3 {
    class numbered {
        friend void f(const numbered&);
    private:
        int id;
    public:
        static int counter;
        numbered() {
            id = counter++;
        }
        numbered(const numbered& n) {
            id = counter++;
        }
    };
    int numbered::counter = 0;
    void f(const numbered& n) { cout << n.id << endl; }
}

/**
 *  Practise 13.18
 */
namespace Practise_13_18 {
    class Employee {
        friend ostream& operator<<(ostream &, const Employee&);
    private:
        string name;
        unsigned long ID;
    public:
        static int counter;
        Employee() : Employee("") {}
        Employee(string n) : name(n) { ID = counter++; }
    };
    int Employee::counter = 0;
    ostream& operator<<(ostream& os, const Employee& e) {
        if (e.name.length() != 0) {
            os << e.name << " " << e.ID;
        } else {
            os << e.ID;
        }
        return os;
    }
}

namespace Practise_13_22 {
    class HasPtr {
        friend ostream& operator<<(ostream& os, const HasPtr& hp);
    public:
        HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
        HasPtr(const HasPtr& hp) {
            ps = new string(*hp.ps);
            i = hp.i;
        }
        HasPtr& operator=(const HasPtr& hp) {
            ps = new string(*hp.ps);
            i = hp.i;
            return *this;
        }
        ~HasPtr() {
            delete ps;
        }
    private:
        string *ps;
        int i;
    };
    ostream& operator<<(ostream& os, const HasPtr& hp) {
        printf("%ld", (long)hp.ps);
        return os;
    }
}

int main(int argc, const char * argv[]) {
    
    using namespace Practise_13_22;
    
    HasPtr hp("yanghan");
    cout << hp << endl;
    HasPtr hp1 = hp;
    cout << hp1 << endl;
    
    return 0;
}
