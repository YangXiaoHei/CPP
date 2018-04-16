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
#include <fstream>

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
        /**
         *  输入运算符必须处理可能失败的情况，而输出运算符不需要
         */
        friend istream& operator>>(istream& is, Sales_data& s) {
            is >> s.bookNo >> s.units_sold >> s.revenue;
            if (!is) s = Sales_data();
            return is;
        }
        friend Sales_data operator+(const Sales_data &a, const Sales_data &b) {
            Sales_data sum = a;
            sum += b;
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

namespace Practise_14_04 {
    void test() {
        
        /**
         *  %  对称性，不应该是类成员
            %=  类成员
            ++ 类成员
            ->   -> () [] 只能是类成员
            <<  不应该是类成员
            &&  不应该是类成员
            ==  对称性，不应该是类成员
            ()  -> () [] 只能是类成员
         */
    }
}

namespace Practise_14_05 {
    class Book {
        
        friend bool operator==(const Book &a, const Book &b);
        friend bool operator!=(const Book &a, const Book &b);
        friend ostream& operator<<(ostream &os, const Book &b);
        friend istream& operator>>(istream &is, Book &b);
        
    public:
        Book() = default;
        Book(const string &n, const string &a) : name(n), author(a) {}
        Book(Book &&b) : name(std::move(b.name)), author(std::move(b.author)) { }
        Book& operator=(Book &&b) {
            name = std::move(b.name);
            author = std::move(b.author);
            return *this;
        }
        Book& operator=(initializer_list<string> il) {
            auto it = il.begin();
            author = *it++;
            name = *it;
            return *this;
        }
        
    private:
        string name;
        string author;
    };
    
    bool operator==(const Book &a, const Book &b) {
        return a.name == b.name && a.author == b.author;
    }
    bool operator!=(const Book &a, const Book &b) {
        return !(a == b);
    }
    ostream& operator<<(ostream &os, const Book &b) {
        os << b.author << " : " << b.name;
        return os;
    }
    istream& operator>>(istream &is, Book &b) {
        is >> b.author >> b.name;
        if (!is)  b = Book();
        return is;
    }
    void test() {
        
    }
}

namespace Practise_14_06 {
    void test() {
        /**
         *  见 Practise_14_02
         */
    }
}

namespace Practise_14_07 {
    void test() {
        /**
         *  太简单
         */
    }
}

namespace Practise_14_08 {
    void test() {
        /**
         *  见 Practise_14_05
         */
    }
}


namespace Practise_14_09 {
    void test() {
        /**
         *  见 Practise_14_02
         */
    }
}

namespace Practise_14_10 {
    void test() {
        /**
         *  0-201-99999-9 10 24.95
         
            这个很 OK
         
            10 24.95 0-210-99999-9
         
            10 被当作了 bookNo
            24 被当作了 units_sold
            0.95 被当作 price
         
            然后返回，这个也是 OK 的，只不过和你的意图不一致
         */
    }
}

namespace Practise_14_11 {
    void test() {
        
        /**
         *  结果乱套了呗
         
            s.revenue = 24 * 0.95
         */
    }
}

namespace Practise_14_12 {
    void test() {
        /**
         *  见 Practise_14_05
         */
    }
}

namespace Practise_14_13 {
    void test() {
        /**
         *  我觉得不需要耶
         */
    }
}

namespace Practise_14_14 {
    void test() {
        /**
         *  如果使用 operator+
            那么首先，创建一个对象
            有可能要做一些额外的赋值工作
            然后将该对象的所有字段都增加
            然后返回该对象，返回该对象时会触发一次拷贝构造或者移动构造
         
            如果使用 operator+=
            那么首先触发一次拷贝构造（精确匹配）
            然后将该对象所有字段增加  // 不用做额外的赋值工作，因为使用现成的对象
            然后返回该对象，返回该对象时触发一次拷贝构造或者移动构造
            在最好情况下，使用 operator+= 仅需要一次拷贝构造和一次移动构造
         
         */
    }
}

namespace Practise_14_15 {
    void test() {
        /**
         *  Book 不应该包含其他运算符了～不论是逻辑还是算术
         */
    }
}

namespace Practise_14_16 {
    
    class StrBlobPtr;
    /**
     *  StrBlob
     */
    class StrBlob {
        friend class StrBlobPtr;
        friend bool operator==(const StrBlob& a, const StrBlob& b) {
            return *a.data == *b.data;
        }
        friend bool operator!=(const StrBlob& a, const StrBlob& b) {
            return !(a == b);
        }
    public:
        StrBlob() : data(make_shared<vector<string>>()) {}
        StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
        string& front() const {
            chk_size(0, "empty!");
            return data->front();
            
        }
        
        string& operator[](size_t n) {
            return (*data)[n];
        }
        const string& operator[](size_t n) const {
            return (*data)[n];
        }
        
        string& back() const {
            chk_size(0, "empty!");
            return data->back();
        }
        size_t size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        
        StrBlobPtr begin();
        StrBlobPtr end();
        
    private:
        shared_ptr<vector<string>> data;
        void chk_size(size_t i, const string &msg) const {
            if (i >= data->size()) {
                throw out_of_range(msg);
            }
        }
    };
    
    /**
     *  StrBlobPtr
     */
    class StrBlobPtr {
        friend bool operator==(const StrBlobPtr& a, const StrBlobPtr& b) {
            auto reta = a.wptr.lock();
            auto retb = b.wptr.lock();
            if ((reta == nullptr && retb != nullptr) ||
                (reta != nullptr && retb == nullptr)) {
                return false;
            }
            return (*reta) == (*retb) && a.cur == b.cur;
        }
        friend bool operator!=(const StrBlobPtr& a, const StrBlobPtr& b) {
            return !(a == b);
        }
    public:
        StrBlobPtr(StrBlob& s) : wptr(s.data), cur(0) {}
        StrBlobPtr(StrBlob& s, size_t c) : wptr(s.data), cur(c) {}
        
        string operator*() {
            auto ret = chk_return();
            return (*ret)[cur];
        }
        
        string& operator[](size_t n) {
            auto d = chk_return();
            return (*d)[n];
        }
        
        const string& operator[](size_t n) const {
            auto d = chk_return();
            return (*d)[n];
        }
        
        StrBlobPtr& operator++() {
            chk_return();
            ++cur;
            return *this;
        }
        
        StrBlobPtr& operator--() {
            --cur;
            chk_return();
            return *this;
        }
        
        StrBlobPtr operator++(int) {
            StrBlobPtr old = *this;
            ++*this;
            return old;
        }
        
        StrBlobPtr operator--(int) {
            StrBlobPtr old = *this;
            --*this;
            return old;
        }
        
        StrBlobPtr& operator+=(size_t n) {
            cur += n;
            return *this;
        }
        
        StrBlobPtr& operator-=(size_t n) {
            cur -= n;
            return *this;
        }
        
        StrBlobPtr operator+(size_t n) {
            StrBlobPtr h = *this;
            *this += n;
            return h;
        }
        
        StrBlobPtr operator-(size_t n) {
            StrBlobPtr h = *this;
            *this -= n;
            return h;
        }
        
        
    private:
        weak_ptr<vector<string>> wptr;
        size_t cur;
        shared_ptr<vector<string>> chk_return() const {
            auto ret = wptr.lock();
            if (!ret) {
                throw runtime_error("no exitst");
            }
            if (cur >= ret->size()) {
                throw out_of_range("out of range");
            }
            return ret;
        }
    };
    
    StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
    StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }
    
    /**
     *  StrVec
     */
    class StrVec {
        friend bool operator==(const StrVec &a, const StrVec &b) {
            if (a.size() != b.size() || a.capacity() != b.capacity())
                return false;
            for (string *p = a.elements, *q = b.elements; p != a.first_free; ++p, ++q)
                if (*p != *q)
                    return false;
            return true;
        }
        friend bool operator!=(const StrVec &a, const StrVec &b) {
            return !(a == b);
        }
    public:
        StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
        StrVec(initializer_list<string> il) {
            for (auto it = il.begin(); it != il.end(); ++it) {
                push_back(*it);
            }
        }
        StrVec& operator=(initializer_list<string> il) {
            free();
            for (auto it = il.begin(); it != il.end(); ++it) {
                push_back(*it);
            }
            return *this;
        }
        
        string& operator[](size_t n) {
            return elements[n];
        }
        const string& operator[](size_t n) const {
            return elements[n];
        }
        
        StrVec(const StrVec& s) {
            auto data = alloc_n_copy(s.begin(), s.end());
            elements = data.first;
            first_free = cap = data.second;
        }
        StrVec& operator=(const StrVec& s) {
            auto data = alloc_n_copy(s.begin(), s.end());
            free();
            elements = data.first;
            first_free = cap = data.second;
            return *this;
        }
        StrVec(StrVec &&s) {
            auto data = alloc_n_move(s.begin(), s.end());
            elements = data.first;
            first_free = cap = data.second;
            s.elements = s.first_free = s.cap = nullptr;
        }
        StrVec& operator=(StrVec &&s) {
            if (this != &s) {
                free();
                auto data = alloc_n_move(s.begin(), s.end());
                elements = data.first;
                first_free = cap = data.second;
                s.elements = s.first_free = s.cap = nullptr;
            }
            return *this;
        }
        
        void push_back(const string &s) {
            chk_n_alloc();
            alloc.construct(first_free++, s);
        }
        
        string *begin() const { return elements; }
        string *end() const { return first_free; }
        size_t size() const { return first_free - elements; }
        size_t capacity() const { return cap - elements; }
        
        ~StrVec() {
            free();
        }
        
    private:
        static allocator<string> alloc;
        string *elements;
        string *first_free;
        string *cap;
        void free() {
            if (elements) {
                auto p = first_free;
                while (p != elements) {
                    alloc.destroy(--p);
                }
                alloc.deallocate(elements, cap - elements);
            }
        }
        void chk_n_alloc() { if (size() == capacity()) reallocate(); }
        void reallocate() {
            size_t new_cap = size() ? size() * 2 : 1;
            auto data = alloc.allocate(new_cap);
            auto dest = uninitialized_copy(make_move_iterator(elements),
                                           make_move_iterator(first_free), data);
            elements = data;
            first_free = dest;
            cap = elements + new_cap;
        }
        pair<string *, string *> alloc_n_copy(const string *a, const string *b) {
            auto data = alloc.allocate(b - a);
            return { data, uninitialized_copy(a, b, data)};
        }
        pair<string *, string *> alloc_n_move(const string *a, const string *b) {
            auto data = alloc.allocate(b - a);
            return { data, uninitialized_copy(make_move_iterator(a),
                                              make_move_iterator(b), data) };
        }
    };
    allocator<string> StrVec::alloc;
    
    /**
     *  String
     */
    class String {
        friend bool operator==(const String &a, const String &b) {
            if (a.length() != b.length())
                return false;
            for (char *p = a.begin, *q = b.begin; p != a.end; ++p, ++q)
                if (*p != *q)
                    return false;
            return true;
        }
        friend bool operator!=(const String &a, const String &b) {
            return !(a == b);
        }
    public:
        String() : String("") {}
        String(const char *p) {
            char *q = const_cast<char *>(p);
            while (*q) ++q;
            range_initializer(p, q);
        }
        char& operator[](size_t n) {
            return begin[n];
        }
        const char& operator[](size_t n) const {
            return begin[n];
        }
        ~String() {
            free();
        }
        size_t length() const { return end - begin; }
    private:
        static allocator<char> alloc;
        char *begin;
        char *end;
        void free() { alloc.deallocate(begin, end - begin); }
        pair<char *, char *> alloc_n_copy(const char *b, const char *e) {
            auto data = alloc.allocate(e - b);
            return { data, uninitialized_copy(b, e, data)};
        }
        void range_initializer(const char *b, const char *e) {
            auto data = alloc_n_copy(b, e);
            begin = data.first;
            end = data.second;
        }
    };
    allocator<char> String::alloc;
    
    void test() {
        
    }
}

namespace Practise_14_19 {
    void test() {
        /**
         *  需要关系运算符，因为两本书是否相同需要判定条件，但不需要逻辑运算符
         */
    }
}

namespace Practise_14_20 {
    void test() {
        /**
         *  见 Practise_14_02
         */
    }
}

namespace Practise_14_21 {
    class A {
        friend A operator+(const A &a, const A &b) {
            A x;
            x.bookNo = a.bookNo;
            x.units_sold = a.units_sold + b.units_sold;
            x.revenue = a.revenue + b.revenue;
            return x;
        }
    public:
        A() = default;
        A(const string &s, unsigned u, double r) : bookNo(s), units_sold(u), revenue(r) {}
        A(const string &s) : A(s, 0, 0.0) {}
        
        A& operator=(const string &s) {
            bookNo = s;
            return *this;
        }
        A& operator+=(const A &b) {
            A olda = *this;
            *this = olda + b;
            // 拷贝赋值运算符，+ 里面还用了两个拷贝构造，没必要
            return *this;
        }
    private:
        string bookNo;
        unsigned units_sold;
        double revenue;
    };
    void test() {
        /**
         *  见注释
         */
    }
}

namespace Practise_14_22 {
    void test() {
        /**
         *  见 Practise_14_21
         */
    }
}

namespace Practise_14_23 {
    void test() {
        /**
         *  见 Practise_14_16
         */
    }
}

namespace Practise_14_24 {
    void test() {
        /**
         *  见 Practise_14_05
         */
    }
}

namespace Practise_14_25 {
    void test() {
        /**
         *  见 Practise_14_05
         */
        using Practise_14_05::Book;
        Book b = { "yanghan", "C++ Primer5"};
        cout << b << endl;
    }
}

namespace Practise_14_26 {
    void test() {
        /**
         *  见 Practise_14_16
         */
    }
}

namespace Practise_14_27 {
    void test() {
        /**
         *  见 Practise_14_16
         */
    }
}
namespace Practise_14_28 {
    void test() {
        /**
         *  见 Practise_14_16
         */
    }
}
namespace Practise_14_29 {
    void test() {
        /**
         *  ++ 和 -- 改变了自身的状态
         */
    }
}

namespace YH {
    class StrBlobPtr;
    class ConstStrBlobPtr;
    class StrBlob {
        friend class StrBlobPtr;
        friend class ConstStrBlobPtr;
    public:
        StrBlob() : data(make_shared<vector<string>>()) {}
        StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
        size_t size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        void push_back(const string &s) {
            data->push_back(s);
        }
        string& front() {
            chk_size(0, "empty");
            return data->front();
        }
        string& back() {
            chk_size(0, "empty");
            return data->back();
        }
        StrBlobPtr begin();
        StrBlobPtr end();
        
    private:
        shared_ptr<vector<string>> data;
        void chk_size(size_t n, const string &msg) {
            if (n >= data->size()) {
                throw out_of_range(msg);
            }
        }
    };
    class StrBlobPtr {
    public:
        StrBlobPtr(const StrBlob& s) : wptr(s.data), cur(0) {}
        StrBlobPtr(const StrBlob& s, size_t sz) : wptr(s.data), cur(sz) {}
        
        string& operator*() const {
            auto ret = chk_return();
            return (*ret)[cur];
        }
        
        string* operator->() {
            return &this->operator*();
        }
        
        StrBlobPtr& operator++() {
            chk_return();
            ++cur;
            return *this;
        }
        
        StrBlobPtr& operator--() {
            --cur;
            chk_return();
            return *this;
        }
        
        StrBlobPtr operator++(int) {
            StrBlobPtr old = *this;
            ++*this;
            return old;
        }
        
        StrBlobPtr operator--(int) {
            StrBlobPtr old = *this;
            --*this;
            return old;
        }
        
    private:
        size_t cur;
        weak_ptr<vector<string>> wptr;
        shared_ptr<vector<string>> chk_return() const {
            auto ret = wptr.lock();
            if (!ret) {
                throw runtime_error("runtime err");
            }
            if (cur >= ret->size()) {
                throw out_of_range("out of range");
            }
            return ret;
        }
    };
    
    StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
    StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }
    
    class A {
    public:
        A(const StrBlobPtr &s) : ptr(make_shared<StrBlobPtr>(s)) {}
        StrBlobPtr& operator*() {
            return *(ptr);
        }
        StrBlobPtr* operator->() {
            return & this->operator*();
        }
    private:
        shared_ptr<StrBlobPtr> ptr;
    };
    
    class ConstStrBlobPtr {
    public:
        ConstStrBlobPtr(const StrBlob& s) : wptr(s.data), cur(0) {}
        ConstStrBlobPtr(const StrBlob& s, size_t cu) : wptr(s.data), cur(cu) {}
        
        const string& operator*() {
            auto ret = chk_size();
            return (*ret)[cur];
        }
        
        ConstStrBlobPtr& operator++() {
             ++cur;
            chk_size();
            return *this;
        }
        
        ConstStrBlobPtr& operator--() {
            chk_size();
            --cur;
            return *this;
        }
        
        ConstStrBlobPtr operator++(int) {
            ConstStrBlobPtr old = *this;
            ++*this;
            return old;
        }
        
        ConstStrBlobPtr operator--(int) {
            ConstStrBlobPtr old = *this;
            --*this;
            return old;
        }
        
    private:
        weak_ptr<vector<string>> wptr;
        size_t cur;
        shared_ptr<vector<string>> chk_size() const {
            auto ret = wptr.lock();
            if (!ret) throw runtime_error("runtime error");
            if (cur >= ret->size()) throw out_of_range("out of range");
            return ret;
        }
    };
    
    void test() {
        
    }
}

namespace Practise_14_31 {
    void test() {
        /**
         *  因为没有动态内存的申请
         */
    }
}

namespace YH1 {
    struct absInt {
        int operator()(int val) const {
            return val < 0 ? -val : val;
        }
    };
    class PrintString {
    public:
        PrintString(ostream& o = cout, char c = ' ') : os(o), sep(c) {}
        void operator()(const string &s) const { os << s << sep; }
    private:
        ostream &os;
        char sep;
    };
    void test() {
//        int i = -42;
//        absInt abs;
//        cout << abs(i) << endl;
        
        PrintString printer;
        printer("haha");
        
        PrintString errors(cerr, '\n');
        errors("haha");
    }
}

namespace Practise_14_33 {
    void test() {
        /**
         *  256 个
         */
    }
}

namespace Practise_14_34 {
    struct A {
        int operator()(bool success, int second, int third) {
            return success ? second : third;
        }
    };
    void test() {
        A a;
        cout << a(true, 3, 2) << endl;
        cout << a(false, 3, 2) << endl;
    }
}

namespace Practise_14_35 {
    struct A {
        string operator()(istream& is) {
            string s;
            is >> s;
            if (!is) return string();
            return s;
        }
    };
    void test() {
        A a;
        cout << a(cin) << endl;
    }
}

namespace Practise_14_36 {
    void test() {
        using Practise_14_35::A;
        A a;
        vector<string> vs;
        for (int i = 0; i < 10; i++) {
            vs.push_back(a(cin));
        }
        for (auto it = vs.cbegin(); it != vs.cend(); ++it) {
            cout << *it << endl;
        }
    }
}

namespace Practise_14_37 {
    void test() {
        vector<string> vs = { "1", "5", "3", "4", "5", "6", "7", "5"};
        replace_if(vs.begin(), vs.end(), [](const string &a) { return a == "5"; }, "10");
        for (auto it = vs.begin(); it != vs.end(); ++it) {
            cout << *it << endl;
        }
    }
}

namespace Practise_14_38 {
    void test() {

        ifstream fin("/Users/bot/Desktop/algs4-data/tinyTale.txt");
        string word;
        map<string, size_t> mapper;
        while (fin >> word) {
            auto rel = mapper.find(word);
            if (rel == mapper.end())
                mapper.insert(make_pair(word, 1));
            else
                mapper.insert(make_pair(word, ++rel->second));
        }
        for (auto it = mapper.begin(); it != mapper.end(); ++it) {
            cout << it->first << "\t:" << it->second << endl;
        }
        
    }
}

namespace Practise_14_39 {
    void test() {
        ifstream fin("/Users/bot/Desktop/algs4-data/tinyTale.txt");
        size_t cnt19 = 0, cnt10 = 0;
        string word;
        while (fin >> word) {
            if (word.length() >= 1 && word.length() <= 9) {
                cnt19++;
            }
            if (word.length() > 10) {
                cnt10++;
            }
        }
        cout << "1 ~ 9 的单词有 : " << cnt19 << endl;
        cout << "10 以上的单词有 : " << cnt10 << endl;
    }
}


int main(int argc, const char * argv[]) {

    Practise_14_39::test();
    
    return 0;
}
