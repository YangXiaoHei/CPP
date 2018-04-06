//
//  main.cpp
//  Learning
//
//  Created by YangHan on 2018/4/5.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>

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
            auto newp = new string(*hp.ps);  // 防范自赋值
            delete ps;
            ps = newp;
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


namespace Practise_13_27 {
    class HasPtr {
    private:
        string *ps;
        int i;
        int *refCount;
    public:
        HasPtr(string s = string()) : ps(new string(s)), i(0) {
            refCount = new int;
            *refCount = 1;
            cout << "constructor ref = " << *refCount << endl;
        }
        HasPtr(const HasPtr& hp) : ps(hp.ps), i(hp.i) {
            refCount = hp.refCount;
            ++*refCount;
            cout << "copy constructor ref = " << *refCount << endl;
        }
        HasPtr& operator=(const HasPtr& hp) {
            if (--*refCount == 0) {
                delete ps;
                delete refCount;
            }
            ++*hp.refCount;
            ps = hp.ps;
            refCount = hp.refCount;
            cout << "assignment ref = " << *refCount << endl;
            return *this;
        }
        ~HasPtr() {
            --*refCount;
            cout << "dealloc ref = " << *refCount << endl;
            if (*refCount == 0) {
                cout << "dealloc release " << endl;
                delete ps;
                delete refCount;
            }
        }
    };
    void test() {
        HasPtr a, b = a, c = b;
        HasPtr d;
        a = d;
    }
}


namespace YH4 {
    class Item {
        // 比较器
        friend int operator<(const Item& a, const Item& b);
        friend int operator>(const Item& a, const Item& b);
        friend int operator<=(const Item& a, const Item& b);
        friend int operator>=(const Item& a, const Item& b);
        friend int operator==(const Item& a, const Item& b);
        friend int operator!=(const Item& a, const Item& b);
        // 打印
        friend ostream& operator<<(ostream& os, const Item& it);
        // swap 用于优化交换性能
        friend void swap(Item &a, Item &b);
    private:
        string *product_name;
        ssize_t *ref;
        int ID;
    public:
        static int counter;
        Item(string pname) :
        product_name(new string(pname)), ID(counter++), ref(new ssize_t(1)) {}
        Item(const Item& it) : product_name(it.product_name), ID(it.ID), ref(it.ref) {
            ++*ref;
        }
        Item& operator=(const Item& it) {
            if (--*ref == 0) {
                delete product_name;
                delete ref;
            }
            ++*it.ref;
            product_name = it.product_name;
            ref = it.ref;
            ID = it.ID;
            return *this;
        }
        ~Item() {
            if (--*ref == 0) {
                delete product_name;
                delete ref;
                
            }
        }
    };
    int Item::counter = 0;
    // 比较器
    int operator<(const Item& a, const Item& b) { return a.ID < b.ID; }
    int operator>(const Item& a, const Item& b) { return a.ID > b.ID; }
    int operator<=(const Item& a, const Item& b) { return a.ID <= b.ID; }
    int operator>=(const Item& a, const Item& b) { return a.ID >= b.ID; }
    int operator==(const Item& a, const Item& b) { return a.ID == b.ID; }
    int operator!=(const Item& a, const Item& b) { return a.ID != b.ID; }
    // 打印
    ostream& operator<<(ostream& os, const Item& it) {
        os << "{" << *it.product_name << " " << it.ID << "} ";
        return os;
    }
    // 交换
    void swap(Item& a, Item& b) {
        int ID = a.ID;
        a.ID = b.ID;
        b.ID = ID;
    }
    
    void test() {
        vector<Item> v;
        string pname = "YangHan";
        for (int i = 0; i < 1000000; i++) {
            v.push_back(Item(pname));
        }
        /**
         *  使用自定义的 swap 可以让性能快上一倍....
         */
        clock_t s = clock();
        random_shuffle(v.begin(), v.end());
        clock_t e = clock();
        printf("time cost : %.3f\n", (e - s) * 1.0 / CLOCKS_PER_SEC );
    }
}

namespace YH5 {
    class Folder;
    /**
     *  Message
     */
    class Message {
        friend ostream& operator<<(ostream& os, const Message& f);
        friend ostream& operator<<(ostream& os, const Folder& f);
        friend class Folder;
    private:
        set<Folder*> folders;
        string contents;
        void addToFolder(const Message& m);
        void removeFromFolder();
    public:
        explicit Message(const string &str = "") : contents(str) {}
        Message(const Message& m);
        Message& operator=(const Message& m);
        ~Message();
        
        Message& save(Folder&);
        Message& remove(Folder&);
    };
    
    /**
     *  Folder
     */
    class Folder {
        friend ostream& operator<<(ostream& os, const Folder& f);
    private:
        string folderName;
        set<Message *> msgs;
    public:
        Folder(const string& s = "") : folderName(s) {}
        Folder& addMsg(Message *m);
        Folder& remMsg(Message *m);
        ~Folder();
    };
    
    /**
     *  Message Define
     */
    Message& Message::save(YH5::Folder& f) {
        folders.insert(&f);
        f.addMsg(this);
        return *this;
    }
    Message& Message::remove(YH5::Folder &f) {
        folders.erase(&f);
        f.remMsg(this);
        return *this;
    }
    void Message::addToFolder(const YH5::Message &m) {
        for (auto f : m.folders)
            f->addMsg(this);
    }
    void Message::removeFromFolder() {
        for (auto f : folders)
            f->remMsg(this);
    }
    Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
        addToFolder(m);
    }
    Message& Message::operator=(const YH5::Message &m) {
        removeFromFolder();
        contents = m.contents;
        folders = m.folders;
        addToFolder(m);
        return *this;
    }
    ostream& operator<<(ostream& os, const Message& f) {
        os << f.contents;
        return os;
    }
    Message::~Message() {
        for (auto f : folders)
            f->remMsg(this);
    }
    
    /**
     *  Folder
     */
    Folder& Folder::addMsg(YH5::Message *m) {
        msgs.insert(m);
        return *this;
    }
    Folder& Folder::remMsg(YH5::Message *m) {
        msgs.erase(m);
        return *this;
    }
    ostream& operator<<(ostream& os, const Folder& f) {
        os << f.folderName << endl;
        for (auto it = f.msgs.begin(); it != f.msgs.end(); ++it) {
            os << "\t" << **it << endl;
        }
        return os;
    }
    Folder::~Folder() {
        for (auto m : msgs)
            m->folders.erase(this);
    }
    
    void test() {
        
        Message a("Hello World"), b("C++ Primer"), c("YangHan is pig"), d("Algorithms");
        Folder InBox("InBox"), Flagged("Flagged"), Drafts("Drafts");
        
        a.save(InBox).save(Flagged).save(Drafts);
        b.save(InBox).save(Drafts);
        c.save(Flagged).save(Drafts);
        d.save(Flagged).save(InBox);
        
        cout << InBox << endl;
        cout << Flagged << endl;
        cout << Drafts << endl;

        a = c;

        cout << "------" << endl;
        cout << InBox << endl;
        cout << Flagged << endl;
        cout << Drafts << endl;
        
        Message f = d;
        
        cout << "------" << endl;
        cout << InBox << endl;
        cout << Flagged << endl;
        cout << Drafts << endl;
    }
}





int main(int argc, const char * argv[]) {
    
    YH5::test();
    
    
    return 0;
}
