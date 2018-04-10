//
//  main.cpp
//  Second
//
//  Created by YangHan on 2018/4/9.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <vector>

#define INPUT_DECLARE(_type_) friend ostream& operator<<(ostream&, const _type_&);
#define INPUT_DEFINE(_type_, _closure_) \
ostream& operator<<(ostream& os, const _type_& value) \
{\
do { _closure_ } while(0); \
return os;\
}

using namespace std;

namespace YH {
    class MyStr {
        INPUT_DECLARE(MyStr)
    public:
        MyStr(const char *s) : val(s) { cout << "constrctors" << endl; }
        MyStr(const MyStr& m) : val(m.val) { cout << "copy constrctors" << endl; }
    private:
        string val;
    };
    INPUT_DEFINE(MyStr, {
        os << value.val;
    })
    void haha(MyStr m) {
        cout << m << endl;
    }
    void test() {
        haha("haha");
    }
}

namespace Practise_13_01 {
    void test() {
        /**
         *  拷贝构造函数是一种第一个参数类型是 const type &，并且其他参数都有默认值的构造函数
         *
         *  1，使用 = 定义值
            2，将对象传递给非引用型形参
            3，在返回值为非引用型的函数中返回对象
         *  4，列表初始化数组或聚合类
         *  5，某些容器类对分配的对象使用拷贝初始化
         *
         */
    }
}

namespace Practise_13_02 {
    void test() {
        /**
         *  为了调用拷贝构造函数，必须拷贝它的实参，为了拷贝实参，又需要调用拷贝构造函数，死循环
         */
    }
}

namespace Practise_13_03_ {
    class StrBlob {
        friend ostream& operator<<(ostream&, const StrBlob&);
    public:
        typedef vector<string>::size_type size_type;
        StrBlob() : data(make_shared<vector<string>>()) {}
        StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        void push_back(const string &s) {
            data->push_back(s);
        }
        void pop_back() {
            check(0, "empty!");
            data->pop_back();
        }
        string& front() {
            check(0, "empty");
            return data->front();
        }
        string& back() {
            check(0, "empty");
            return data->back();
        }
    private:
        shared_ptr<vector<string>> data;
        void check(size_type i, const string& m) {
            if (i >= data->size()) {
                throw out_of_range(m);
            }
        }
    };
    ostream& operator<<(ostream& os, const StrBlob& s) {
        for (auto it = s.data->begin(); it != s.data->end(); ++it) {
            os << *it << endl;
        }
        return os;
    }
    void test() {
        StrBlob s({ "haha", "yangha", "lijie" });
        cout << s << endl;
    }
}



namespace Practise_13_03 {
    class StrBlobPtr;
    class StrBlob {
        friend class StrBlobPtr;
        INPUT_DECLARE(StrBlob)
    public:
        typedef vector<string>::size_type size_type;
        StrBlob() : data(make_shared<vector<string>>()) {}
        StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        StrBlobPtr begin();
        StrBlobPtr end();
        void push_back(const string& s) {
            data->push_back(s);
        }
        void pop_back() {
            check(0, "empty");
            data->pop_back();
        }
        const string& front() const {
            check(0, "empty");
            return data->front();
        }
        const string& back() const {
            check(0, "empty");
            return data->back();
        }
    private:
        shared_ptr<vector<string>> data;
        void check(size_type i, const string& s) const {
            if (i >= data->size()) {
                throw out_of_range(s);
            }
        }
    };
    INPUT_DEFINE(StrBlob, {
        for (auto it = value.data->begin(); it != value.data->end(); ++it) {
            os << *it << endl;
        }
    })
    class StrBlobPtr {
    public:
        StrBlobPtr(StrBlob &b) : wptr(b.data), cur(0) {}
        StrBlobPtr(StrBlob &b, size_t sz) : wptr(b.data), cur(sz) {}
        bool operator!=(const StrBlobPtr &s) { return cur != s.cur; }
        string& operator*() {
            auto it = check(cur, "out of range");
            return (*it)[cur];
        }
        StrBlobPtr& operator++() {
            ++cur;
            return *this;
        }
    private:
        size_t cur;
        weak_ptr<vector<string>> wptr;
        shared_ptr<vector<string>> check(size_t i, const string& s) const {
            auto ret = wptr.lock();
            if (!ret) {
                throw runtime_error("not exist err");
            }
            if (i >= ret->size()) {
                throw out_of_range("out of range");
            }
            return ret;
        }
    };
    StrBlobPtr StrBlob::begin() {
        return StrBlobPtr(*this);
    }
    StrBlobPtr StrBlob::end() {
        return StrBlobPtr(*this, data->size());
    }
    void test() {
        StrBlob s = {"haha", "xixi", "heihei"};
        for (StrBlobPtr b = s.begin(); b != s.end(); ++b) {
            cout << *b << endl;
        }
    }
}

namespace Practise_13_04 {
//    class Point {
//    public:
//        Point() { cout << "构造" << endl; }
//        Point(const Point& p) { cout << "拷贝构造" << endl; }
//    };
//    Point global;
//    Point foo_bar(Point arg) {
//        cout << "----" << endl;
//        Point local = arg;
//        cout << "1" << endl;
//        Point *heap = new Point(global);
//        cout << "2" << endl;
//        *heap = local;
//        cout << "3" << endl;
//        Point pa[4] = { local, *heap };
//        cout << "4" << endl;
//        return *heap;
//    }
//    void test() {
//        foo_bar(Point());
//    }
}

namespace Practise_13_05 {
    class HasPtr {
        INPUT_DECLARE(HasPtr)
    public:
        HasPtr(const string& s = string()) : ps(new string(s)), i(0) {}
        HasPtr(const HasPtr& p) : ps(new string(*p.ps)), i(p.i) {}
        HasPtr& operator=(const HasPtr& p) {
            auto d = new string(*p.ps);
            delete ps;
            ps = d;
            i = p.i;
            return *this;
        }
        ~HasPtr() {
            delete ps;
        }
    private:
        string *ps;
        int i;
    };
    INPUT_DEFINE(HasPtr, {
        os << "address : " << value.ps << " content : " << *value.ps;
    })
    void test() {
        HasPtr a("xixi"), b("heihei");
        cout << a << endl;
        cout << b << endl;
        HasPtr c = a;
        cout << c << endl;
        b = c;
        cout << b << endl;
    }
}

namespace Practise_13_06 {
    void test() {
        /**
         *  拷贝赋值运算符是一个叫 operator= 的函数，当赋值发生的时候使用它
            它将赋值运算符右侧的对象中的每个非 static 成员拷贝给 左侧对象的相应非 static 成员
            当你自己没有定义拷贝赋值运算符时，编译器自动帮你合成一个
         */
    }
}

namespace Practise_13_07 {
    void test() {
        /**
         *  StrBlob shared_ptr 的引用计数 + 1
            StrBlobPtr weak_ptr 不会增加引用计数
         */
    }
}

namespace Practise_13_08 {
    class HasPtr {
    public:
        HasPtr(const string& s = string()) : ps(new string(s)), i(0) {}
        HasPtr(const HasPtr& h) : ps(new string(*h.ps)), i(h.i) {}
        HasPtr& operator=(const HasPtr& h) {
            auto d = new string(*h.ps);
            delete ps;
            ps = d;
            i = h.i;
            return *this;
        }
    private:
        string *ps;
        int i;
    };
}

namespace Practise_13_09 {
    void test() {
        /**
         *  析构函数是一个没有参数无法重载的函数，它用于在释放你自己分配的资源，在析构函数体执行后，类就释放那些默认释放的资源。当你没有手动定义析构函数，类会自己为你合成一个
         */
    }
}

namespace Practise_13_10 {
    void test() {
        /**
         *  StrBlob 中的 data 是一个智能指针，StrBlob 对象销毁，因此对它的引用计数减为 0，data 调用析构函数被释放，同时释放 vector 中每个 string，也都被分别调用了析构函数
         
            StrBlobPtr 被释放时不会减少 StrBlob 中的引用计数，因此只是释放自己的资源
         */
    }
}

namespace Practise_13_11 {
    class HasPtr {
    public:
        HasPtr(const string& s = string()) : ps(new string(s)), i(0) {}
        HasPtr(const HasPtr& hp) : ps(new string(*hp.ps)), i(hp.i) {}
        HasPtr& operator=(const HasPtr& hp) {
            auto d = new string(*hp.ps);
            delete ps;
            ps = d;
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
}

namespace Practise_13_12 {
    class Sales_data {
    private:
        string bookNo;
    public:
        Sales_data() { cout << "构造" << endl; }
        Sales_data(const Sales_data& s) : bookNo(s.bookNo) { cout << "拷贝构造" << endl; }
        string isbn() const { return bookNo; }
        ~Sales_data() {
            cout << "析构函数" << endl;
        }
    };
    bool fcn(const Sales_data *trans, Sales_data accum) {
        cout << "1" << endl;
        Sales_data item1(*trans);
        cout << "2" << endl;
        Sales_data item2(accum);
        cout << "3" << endl;
        return item1.isbn() != item2.isbn();
    }
    void test() {
        Sales_data data;
        cout << "----" << endl;
        fcn(&data, data);
        cout << "----" << endl;
    }
}

namespace Practise_13_13 {
    struct X {
        X() { cout << "constructor" << endl; }
        X(const X& x) { cout << "copy" << endl; }
        ~X() { cout << "dealloc" << endl; }
    };
    void test() {
        vector<X> vx;
        cout << "----" << endl;
        vx.push_back(X());
        cout << "1" << endl;
        vx.push_back(X());
        cout << "2" << endl;
    }
}

namespace Practise_13_14 {
    struct X {
        X(const string& s = string()) : s(new string(s)) {}
        ~X() { delete s; }
    private:
        string *s;
    };
    void f(X x) {
        X a = x;
    }
    void test() {
        X b;
        f(b);
        cout << "---" << endl;
    }
}


int main(int argc, const char * argv[]) {

    Practise_13_14::test();
    
    
    return 0;
}
