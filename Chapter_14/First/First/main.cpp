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
        /**
         *  输入运算符必须处理可能失败的情况，而输出运算符不需要
         */
        friend istream& operator>>(istream& is, Sales_data& s) {
            is >> s.bookNo >> s.units_sold >> s.revenue;
            if (!is) s = Sales_data();
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
        
        StrBlobPtr& operator++() {
            ++cur;
            chk_return();
            return *this;
        }
        
    private:
        weak_ptr<vector<string>> wptr;
        size_t cur;
        shared_ptr<vector<string>> chk_return() {
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
    
    void test() {
        
    }
}


















int main(int argc, const char * argv[]) {

    Practise_14_10::test();
    
    return 0;
}
