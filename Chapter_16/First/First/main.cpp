//
//  main.cpp
//  First
//
//  Created by YangHan on 2018/4/21.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

namespace YH {
    template <typename T>
    int compare(const T &v1, const T &v2)
    {
        return v1 < v2 ? -1 : v1 > v2 ? 1 : 0;
    }
    void test()
    {
        cout << compare(1, 2) << endl;
        vector<int> v1{1, 2, 3}, v2{4, 5, 6};
        cout << compare(v1, v2) << endl;
    }
}

namespace YH1 {
    /**
     *  类型参数，非类型参数
        非类型模版参数的模版实参必须是常量表达式
     */
    template <unsigned N, unsigned M>
    int compare(const char (&p1)[N], const char (&p2)[M])
    {
        return strcmp(p1, p2);
    }
    void test()
    {
        compare("hi", "mom");
        // 实例出如下版本
        // int compare(const char (&p1)[3], const char (&p2)[4]);
    }
}

namespace YH2 {
    template <typename T> inline T min(const T &a, const T &b)
    {
        return a < b ? a : b;
    }
}

namespace Practise_16_01 {
    void test()
    {
        /**
         *  编译器根据模版生成针对某中具体类型的代码
         */
    }
}

namespace Practise_16_02 {
    template <typename T>
    int compare(const T &a, const T &b)
    {
        return a < b ? -1 : (b < a) ? 1 : 0;
    }
    void test()
    {
        cout << compare(string("haha"), string("yanghan")) << endl;
    }
}

namespace Practise_16_03 {
    class Sales_data
    {
        friend bool operator<(const Sales_data &a, const Sales_data &b);
    public:
        Sales_data(const string &s) : bookNo(s) {}
    private:
        string bookNo;
    };
    bool operator<(const Sales_data &a, const Sales_data &b)
    {
        return a.bookNo < b.bookNo;
    }
    template <typename T>
    int compare(const T &a, const T &b)
    {
        return a < b ? -1 : (b < a) ? 1 : 0;
    }
    void test()
    {
        Sales_data d1("1234"), d2("23455");
        cout << compare(d1, d2) << endl;
    }
}

namespace Practise_16_04 {
    template <typename IteratorType, typename ValueType>
    IteratorType yh_find(IteratorType begin, IteratorType end, ValueType key)
    {
        for (IteratorType b = begin; b != end; ++b) {
            if (key == *b) {
                return b;
            }
        }
        return end;
    }
    void test()
    {
        vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};
        list<string> l1{ "yanghan", "lijie", "zhangyafang", "chenyanyu" };
        
        cout << *yh_find(v1.begin(), v1.end(), 4) << endl;
        cout << *yh_find(l1.begin(), l1.end(), "lijie") << endl;
    }
}

namespace Practise_16_05 {
    template <typename T, size_t N>
    void yh_print(const T (&p)[N])
    {
        for (size_t i = 0; i < N; ++i) {
            cout << p[i] << endl;
        }
    }
    void test()
    {
        yh_print({1, 2, 3, 4, 5, 6});
        double a[] = {4.8, 5.9};
        string b[] = { "yanghan", "lijie" };
        yh_print(a);
        yh_print(b);
    }
}

namespace Practise_16_06 {
    template <typename T>
    T *begin(T (&a)[])
    {
        return a;
    }
    template <typename T, size_t N>
    T *end(T (&a)[N])
    {
        return a + N;
    }
    void test()
    {
        
    }
}

namespace Practise_16_07 {
    template <typename T, size_t N>
    constexpr size_t size_of_array(const T (&a)[N])  /* 必须加 const 才能传递 { 1, 2, 3 } */
    {
        return N;
    }
    void test()
    {
        cout << size_of_array({1, 2, 3, 4}) << endl;
        string a[] = { "yanghan", "lijie" };
        cout << size_of_array(a) << endl;
    }
}

typedef int HAHA;

namespace Practise_16_08 {
    void test()
    {
        HAHA a;
        
        /**
         * 只有 string 和 vector 等一些标准库类型有下标运算符，而并非全部如此
            与之类似，所有标准库容器的迭代器都定义了 == 和 !=，但是它们中的大多数都没有定义 < 运算符
            因此，只要养成使用迭代器和 != 的习惯，就不用太在意用的到底是哪种容器类型
         */
    }
}

namespace YH3 {
    
    template <typename> class BlobPtr;
    template <typename> class Blob;
    
    /**
     *  Blob
     */
    template <typename T>
    class Blob
    {
        friend class BlobPtr<T>;
        
    public:
        typedef T value_type;
        typedef typename vector<T>::size_type size_type;
        Blob();
        Blob(initializer_list<T> il);
        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        void push_back(const T &t) { data->push_back(t); }
        void push_back(T &&t) { data->push_back(std::move(t)); }
        void pop_back();
        T& back();
        T& operator[](size_type i);
    private:
        shared_ptr<vector<T>> data;
        void check(size_type i, const string &msg) const;
    };
    
    template <typename T>
    bool operator==(const Blob<T> &a, const Blob<T> &b)
    {
        return a.data == b.data;
    }
    
    template <typename T>
    void Blob<T>::check(size_type i, const string &msg) const
    {
        if (i >= data->size()) {
            throw out_of_range(msg);
        }
    }
    template <typename T>
    T& Blob<T>::back()
    {
        check(0, "back on empty Blob");
        return data->back();
    }
    template <typename T>
    T& Blob<T>::operator[](size_type i)
    {
        check(i, "subscript out of range");
        return (*data)[i];
    }
    template <typename T>
    void Blob<T>::pop_back()
    {
        check(0, "pop_back on empty Blob");
        data->pop_back();
    }
    
    template <typename T>
    Blob<T>::Blob() : data(make_shared<vector<T>>()) {}
    
    template <typename T>
    Blob<T>::Blob(initializer_list<T> il) : data(make_shared<vector<T>>(il)) {}
    
    
    
    /**
     *  BlobPtr
     */
    template <typename T>
    class BlobPtr
    {
    public:
        BlobPtr() : curr(0) {}
        BlobPtr(BlobPtr<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
        T& operator*() const
        {
            auto p = check(curr, "deference past end");
            return (*p)[curr];
        }
        BlobPtr& operator++();
        BlobPtr& operator--();
        
        BlobPtr operator++(int);
        BlobPtr operator--(int);
    private:
        shared_ptr<vector<T>> check(size_t, const string&) const;
        weak_ptr<vector<T>> wptr;
        size_t curr;
    };
    
    template <typename T>
    BlobPtr<T> BlobPtr<T>::operator++(int)
    {
        BlobPtr ret = *this;
        ++*this;
        return ret;
    }
    template <typename T>
    BlobPtr<T> BlobPtr<T>::operator--(int)
    {
        BlobPtr ret = *this;
        --*this;
        return ret;
    }
    template <typename T>
    BlobPtr<T>& BlobPtr<T>::operator++()
    {
        check(curr, "out of range");
        ++curr;
        return *this;
    }
    template <typename T>
    BlobPtr<T>& BlobPtr<T>::operator--()
    {
        --curr;
        check(curr, "out of range");
        return *this;
    }
    void test()
    {
        Blob<int> b = { 1, 2, 3 };
        Blob<int> c = { 3, 4, 5 };
    }
}

namespace YH4 {
    
    // 前置声明，在将模版的一个特定实例声明位友元时要用到
    template <typename T> class Pal;
    
    // 普通非模版类
    class C
    {
        friend class Pal<C>; // 用类 C 实例化的 Pal 是 C 的一个友元
        
        // Pal2 的所有实例都是 C 的友元，这种情况无需前置声明
        template <typename T> friend class Pal2;
    };
    
    template <typename T>
    class C2
    {
        // C2 的每个实例都将相同实例化的 Pal 声明作为友元
        friend class Pal<T>;
        
        // Pal2 的所有实例都是 C2 的每个实例的友元，不需要前置声明
        template <typename X> friend class Pal2;
        
        // Pal3 是一个非模版类，它是 C2 所有实例的友元
        friend class Pal3;  // 不需要 Pal3 的前置声明
    };
    
    void test()
    {
        
    }
}

namespace YH5 {
    /**
     *  模版类型别名
     */
    template <typename T>
    class A {};
    template <typename T> using twin = pair<T,T>;
    template <typename T> using partNo = pair<T, unsigned>;
    void test()
    {
        typedef A<string> strA;
        twin<int> win_loss; // win_loss 是一个 pair<int, int>
    }
}

namespace Practise_16_09 {
    void test()
    {
        /**
         *  函数模版：将参数类型泛化，只有当被调用时才根据实参类型实例化函数定义的函数
            类模版：将类用到的参数类型泛化，只有当该类被使用时才实例化类针对某中类型的定义
         */
    }
}

namespace Practise_16_10 {
    void test()
    {
        /**
         *  编译器会重写整个类模版，针对指定的类型生成对应的类定义代码
         */
    }
}

namespace Practise_16_11 {
    /*
    template <typename T> class ListItem;
    template <typename T>
    class List
    {
    public:
        List<T>() = default;
        List<T>(const List<T> &);
        List<T>& operator=(const List<T> &);
        ~List();
        void insert(ListItem<T> *ptr, T value);
    private:
        ListItem<T> *front, *end;
    };
    */
    void test()
    {
        
    }
}

namespace Practise_16_12 {
    
    template <typename X> class BlobPtr;
    template <typename T>
    class Blob
    {
        friend class BlobPtr<T>;
        
    public:
        typedef typename vector<T>::size_type size_type;
        
        Blob();
        Blob(initializer_list<T> il);
        T& operator[](size_t n);
        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        void push_back(const T&);
        void push_back(T&&);
        void pop_back();
        T& front();
        T& back();
        const T& front() const;
        const T& back() const;

        BlobPtr<T> begin();
        BlobPtr<T> end();
        
    private:
        shared_ptr<vector<T>> data;
    };
    
    template <typename T>
    Blob<T>::Blob() : data(make_shared<vector<T>>())
    {
    }
    
    template <typename T>
    Blob<T>::Blob(initializer_list<T> il) : data(make_shared<vector<T>>(il))
    {
    }
    
    template <typename T>
    void Blob<T>::push_back(const T& d)
    {
        data->push_back(d);
    }
    
    template <typename T>
    void Blob<T>::push_back(T &&d)
    {
        data->push_back(d);
    }
    
    template <typename T>
    void Blob<T>::pop_back()
    {
        if (data->empty()) {
            throw out_of_range("pop_back on empty Blob");
        }
        data->pop_back();
    }
    
    template <typename T>
    T& Blob<T>::front()
    {
        if (data->empty()) {
            throw out_of_range("front on empty Blob");
        }
        return data->front();
    }
    
    template <typename T>
    const T& Blob<T>::front() const
    {
        if (data->empty()) {
            throw out_of_range("front on empty Blob");
        }
        return data->front();
    }
    
    template <typename T>
    T& Blob<T>::back()
    {
        if (data->empty()) {
            throw out_of_range("back on empty Blob");
        }
        return data->back();
    }
    
    template <typename T>
    const T& Blob<T>::back() const
    {
        if (data->empty()) {
            throw out_of_range("back on empty Blob");
        }
        return data->back();
    }
    
    template <typename T>
    T& Blob<T>::operator[](size_t n)
    {
        if (n >= data->size()) {
            throw out_of_range("[] out of range");
        }
        return (*data)[n];
    }
    
    template <typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T> &);
    template <typename T> bool operator!=(const BlobPtr<T>&, const BlobPtr<T> &);
    template <typename T> bool operator<(const BlobPtr<T>&, const BlobPtr<T> &);
    template <typename T> bool operator>(const BlobPtr<T>&, const BlobPtr<T> &);
    template <typename T> bool operator<=(const BlobPtr<T>&, const BlobPtr<T> &);
    template <typename T> bool operator>=(const BlobPtr<T>&, const BlobPtr<T> &);
    
    
    template <typename T>
    class BlobPtr
    {
        friend bool operator== <T>(const BlobPtr<T> &a, const BlobPtr<T> &b);
        friend bool operator!= <T>(const BlobPtr<T> &a, const BlobPtr<T> &b);
        friend bool operator< <T>(const BlobPtr<T> &a, const BlobPtr<T> &b);
        friend bool operator> <T>(const BlobPtr<T> &a, const BlobPtr<T> &b);
        friend bool operator<= <T>(const BlobPtr<T> &a, const BlobPtr<T> &b);
        friend bool operator>= <T>(const BlobPtr<T> &a, const BlobPtr<T> &b);
        
        // 加法？
    public:
        BlobPtr(Blob<T> b);
        BlobPtr(Blob<T> b, size_t n);
        
        BlobPtr& operator++();
        BlobPtr& operator--();
        BlobPtr operator++(int);
        BlobPtr operator--(int);
        T& operator*();
        
    private:
        size_t cur;
        weak_ptr<vector<T>> wptr;
        shared_ptr<vector<T>> check(size_t n, const string &msg);
    };
    
    template <typename T>
    shared_ptr<vector<T>> BlobPtr<T>::check(size_t n, const string &msg)
    {
        auto ret = wptr.lock();
        if (!ret)
        {
            throw runtime_error("data already released");
        }
        if (n >= ret->size())
        {
            throw out_of_range(msg);
        }
        return ret;
    }
    
    template <typename T>
    BlobPtr<T>::BlobPtr(Blob<T> b) : wptr(b.data)
    {
    }
    
    template <typename T>
    BlobPtr<T>::BlobPtr(Blob<T> b, size_t n) : wptr(b.data), cur(n)
    {
    }
    
    template <typename T>
    BlobPtr<T>& BlobPtr<T>::operator++()
    {
        check(cur, "++ out of range");
        ++cur;
        return *this;
    }
    
    template <typename T>
    BlobPtr<T>& BlobPtr<T>::operator--()
    {
        --cur; // 溢出
        check(cur, "-- out of range");
        return *this;
    }
    
    template <typename T>
    BlobPtr<T> BlobPtr<T>::operator++(int)
    {
        BlobPtr old = *this;
        ++*this;
        return old;
    }
    
    template <typename T>
    BlobPtr<T> BlobPtr<T>::operator--(int)
    {
        BlobPtr old = *this;
        --*this;
        return old;
    }
    
    template <typename T>
    T& BlobPtr<T>::operator*()
    {
        auto ret = check(cur, "deference out of range");
        return (*ret)[cur];
    }
    
    template <typename T>
    BlobPtr<T> Blob<T>::begin()
    {
        return BlobPtr<T>(*this);
    }
    
    template <typename T>
    BlobPtr<T> Blob<T>::end()
    {
        return BlobPtr<T>(*this, data->size());
    }
    
    template <typename T> bool operator==(const BlobPtr<T>&a, const BlobPtr<T> &b)
    {
        return a.cur == b.cur;
    }
    template <typename T> bool operator!=(const BlobPtr<T>&a, const BlobPtr<T> &b)
    {
        return a.cur != b.cur;
    }
    template <typename T> bool operator<(const BlobPtr<T>&a, const BlobPtr<T> &b)
    {
        return a.cur < b.cur;
    }
    template <typename T> bool operator>(const BlobPtr<T>&a, const BlobPtr<T> &b)
    {
        return a.cur > b.cur;
    }
    template <typename T> bool operator<=(const BlobPtr<T>&a, const BlobPtr<T> &b)
    {
        return a.cur <= b.cur;
    }
    template <typename T> bool operator>=(const BlobPtr<T>&a, const BlobPtr<T> &b)
    {
        return a.cur >= b.cur;
    }
    
    void test()
    {
        Blob<string> bs = { "yanghan", "lijie", "chenyanyu", "xixi", "haha" };
        for (auto it = bs.begin(); it != bs.end(); ++it)
        {
            for (auto &c : *it)
            {
                c = toupper(c);
            }
            cout << *it << endl;
        }
    }
}

namespace Practise_16_13 {
    void test()
    {
        /**
         *  相等性，大小比较，因为数组类型迭代器应该支持逻辑上的加减和大小比较
         */
    }
}

namespace Practise_16_14 {
    
    typedef string::size_type pos;
    
    template <pos H, pos W> class Screen;
    template <pos H, pos W> ostream& operator<< (ostream&, const Screen<H, W> &);
    template <pos H, pos W> istream& operator>> (istream&, Screen<H, W> &);
    
    template <pos H, pos W>
    class Screen
    {
        friend ostream& operator<< <H, W>(ostream&, const Screen<H, W> &);
        friend istream& operator>> <H, W>(istream&, Screen<H, W> &);
        
    public:
        Screen() = default;
        Screen(char c) : content(H * W, c) {}
        char get() const { return content[cur]; }
        char get(pos r, pos c) const { return content[r * W + c]; }
        Screen& move(pos r, pos c) { cur = r * W + c; return *this; }
        Screen& set(char c) { content[cur++] = c; cur = std::min(cur, W * H); return *this; }
        Screen& set(pos r, pos c, char ch) { content[r * W + c] = ch; return *this; }
        
    private:
        string content;
        pos cur = 0;
    };
    
    template <pos H, pos W>
    ostream& operator<< (ostream& os, const Screen<H, W> &s)
    {
        for (pos i = 0; i < H; ++i) {
            for (pos j = 0; j < W; ++j) {
                os << s.get(i, j);
            }
            os << endl;
        }
        os << endl;
        return os;
    }
    
    template <pos H, pos W>
    istream& operator>> (istream& is, Screen<H, W> &screen)
    {
        string s;
        is >> s;
        for (char c : s)
        {
            screen.set(c);
        }
        return is;
    }
    
    void test()
    {
        Screen<4, 4> ss;
        cin >> ss;
        cout << ss;
    }
}

namespace Practise_16_15 {
    void test()
    {
        /**
         *  见 Practise_16_14
         */
    }
}

namespace Practise_16_16 {
    
    template <typename T> class Vec;
    
    template <typename T> ostream& operator<< (ostream &, const Vec<T> &);
    template <typename T> istream& operator>> (istream&, Vec<T>&);
    
    template <typename T>
    class Vec
    {
        friend ostream& operator<< <T>(ostream& os, const Vec<T> &a);
        friend istream& operator>> <T>(istream& is, Vec<T> &a);
        
    public:
        typedef typename vector<T>::size_type size_type;
        
        Vec();
        Vec(initializer_list<T> il);
        Vec& operator=(const Vec&);
        Vec(const Vec&);
        Vec(Vec &&);
        Vec& operator=(Vec &&);
        ~Vec();
        
        size_type size() const { return first_free - elements; }
        size_type capacity() const { return cap - elements; }
        bool empty() const { return size() == 0; }
        
        T *begin() { return elements; }
        T *end() { return first_free; }
        const T *cbegin() const { return elements; }
        const T *cend() const { return first_free; }
        
        T& front() { chk_empty(); return *elements; }
        T& back() { chk_empty(); return *(first_free - 1); }
        
        const T& front() const { chk_empty(); return *elements; }
        const T& back() const { chk_empty(); return *(first_free - 1); }
        
        void push_back(const T &);
        void push_back(T &&);
        void free();
        
    private:
        static allocator<T> alloc;
        T *elements;
        T *first_free;
        T *cap;
        
        void chk_alloc() { if (size() == capacity()) realloc(); }
        void chk_empty() const { if (empty()) throw out_of_range("empty Vec!"); }
        pair<T *, T *> alloc_n_copy(const T *b, const T *e);
        pair<T *, T *> alloc_n_move(const T *b, const T *e);
        void realloc();
    };
    
    template <typename T> allocator<T> Vec<T>::alloc;
    
    template <typename T>
    pair<T *, T *> Vec<T>::alloc_n_copy(const T *b, const T *e)
    {
        auto data = alloc.allocate(e - b);
        return { data, uninitialized_copy(b, e, data) };
    }
    
    template <typename T>
    pair<T *, T *> Vec<T>::alloc_n_move(const T *b, const T *e)
    {
        auto data = alloc.allocate(e - b);
        return { data, uninitialized_copy(make_move_iterator(b),
                                          make_move_iterator(e), data) };
    }
    
    template <typename T>
    Vec<T>& Vec<T>::operator=(const Vec& v)
    {
        auto pair = alloc_n_copy(v.cbegin(), v.cend());
        free();
        elements = pair.first;
        first_free = cap = pair.second;
        return *this;
    }
    
    template <typename T>
    Vec<T>::Vec(const Vec& v)
    {
        auto pair = alloc_n_copy(v.cbegin(), v.cend());
        elements = pair.first;
        first_free = cap = pair.second;
    }
    
    template <typename T>
    Vec<T>::Vec(Vec && v)
    {
        if (this != &v)
        {
            auto pair = alloc_n_move(v.cbegin(), v.cend());
            elements = pair.first;
            first_free = cap = pair.second;
        }
    }
    
    template <typename T>
    Vec<T>& Vec<T>::operator=(Vec &&v)
    {
        if (this != &v)
        {
            auto pair = alloc_n_move(v.cbegin(), v.cend());
            v.elements = v.first_free = v.cap = nullptr;
            elements = pair.first;
            first_free = cap = pair.second;
        }
        return *this;
    }
    
    template <typename T>
    void Vec<T>::realloc()
    {
        size_type new_cap = size() ? size() * 2 : 1;
        auto data = alloc.allocate(new_cap);
        auto dest = data;
        auto src = elements;
        for (size_type i = 0; i < size(); ++i)
        {
            alloc.construct(dest++, std::move(*src++));
        }
        alloc.deallocate(elements, cap - elements);
        elements = data;
        first_free = dest;
        cap =  elements + new_cap;
    }
    
    template <typename T>
    void Vec<T>::free()
    {
        if (elements)
        {
            auto p = first_free;
            while (p != elements)
            {
                alloc.destroy(--p);
            }
            alloc.deallocate(elements, cap - elements);
        }
    }
    
    template <typename T>
    void Vec<T>::push_back(const T &a)
    {
        chk_alloc();
        alloc.construct(first_free++, a);
    }
    
    template <typename T>
    void Vec<T>::push_back(T &&a)
    {
        chk_alloc();
        alloc.construct(first_free++, a);
    }
    
    template <typename T>
    Vec<T>::Vec() : elements(nullptr), first_free(nullptr), cap(nullptr)
    {
    }
    
    template <typename T>
    Vec<T>::Vec(initializer_list<T> il) : Vec()
    {
        for (const T &i : il)
        {
            push_back(i);
        }
    }
    
    template <typename T>
    Vec<T>::~Vec<T>()
    {
        free();
    }
    
    template <typename T>
    ostream& operator<< (ostream& os, const Vec<T>& v)
    {
        for (auto b = v.elements; b != v.first_free; b++)
        {
            os << *b << " ";
        }
        return os;
    }
    
    template <typename T>
    istream& operator>> (istream& is, Vec<T>& v)
    {
        T elem;
        is >> elem;
        v.push_back(elem);
        return is;
    }
    
    void test()
    {
        Vec<string> v1{"a", "b", "c", "d", "e", "f"}, v2{"1", "2", "3", "4", "5"};
        Vec<string> v3 = v1;
        
        v1.push_back("10");
        
        cout << v1 << endl;
        cout << v2 << endl;
        cout << v3 << endl;
    }
}

namespace YH6 {
    template <typename T, typename F = less<T>>
    int compare(const T &v1, const T &v2, F f = F())
    {
        if (f(v1, v2)) return -1;
        if (f(v2, v1)) return 1;
        return 0;
    }
    void test()
    {
        
    }
}

namespace Practise_16_17 {
    
    void test()
    {
        /**
         *  当我们想让编译器知道，当前使用的名字是一个类型时，就必须用 typename 而不是 class
         */
    }
}

namespace Practise_16_18 {
    
    void test()
    {
        /*
         
         (a) template <typename T, typename U, typename V> void f1(T, U, V);
         (b) template <typename T> T f2(int &T);
         (c) template <typename T> inline T foo(T, unsigned int*);
         (d) template <typename T> void f4(T, T);
         (e) typedef char Ctype;
         template <typename T> T f5(T a);
         
         */
    }
}

namespace Practise_16_19 {
    template <typename T>
    void print(const T &a)
    {
        for (typename T::size_type i = 0; i < a.size(); ++i)
            cout << a[i] << endl;
    }
    void test()
    {
        vector<string> s{"1", "2", "3", "4"};
        print(s);
    }
}

namespace Practise_16_20 {
    template <typename T>
    void print(const T &a)
    {
        for (auto it = a.begin(); it != a.end(); ++it)
        {
            cout << *it << endl;
        }
    }
    void test()
    {
        vector<string> s{"1", "2", "3", "4"};
        print(s);
    }
}

namespace YH7 {
    class DebugDelete
    {
    public:
        DebugDelete(ostream &s = cerr) : os(s) {}
        template <typename T> void operator()(T *p) const
        {
            os << "deleting unique_ptr" << endl;
            delete p;
        }
    private:
        ostream &os;
    };
    void test1()
    {
        unique_ptr<int, DebugDelete> p(new int, DebugDelete());
        
        unique_ptr<string, DebugDelete> sp(new string, DebugDelete());
        
    }
    void test()
    {
        double *p = new double;
        DebugDelete d;
        d(p);
        
        int *ip = new int;
        DebugDelete()(ip);  // 在一个临时 DebugDelete 对象上调用 operator()(int *)
    }
}

namespace YH8 {
    template <typename T>
    class Blob
    {
        template <typename It> Blob(It b, It e);
    };
    void test()
    {
        
    }
}

namespace Practise_16_21 {
    class DebugDelete
    {
    public:
        DebugDelete(ostream &os = cerr) : o(os) {}
        template <typename T> void operator()(T *p)
        {
            o << "delete unique_ptr by" << __PRETTY_FUNCTION__ << endl;
            delete p;
        }
    private:
        ostream &o;
    };
    void test()
    {
        double *p = new double;
        DebugDelete d;
        d(p);
        
        int *ip = new int;
        DebugDelete()(ip);
    }
}


int main(int argc, const char * argv[]) {
    
    Practise_16_21::test();
    
    return 0;
}
