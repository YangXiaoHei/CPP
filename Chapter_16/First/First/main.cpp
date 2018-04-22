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
    
    
    template <typename T>
    class BlobPtr
    {
        friend bool operator==(const BlobPtr &a, const BlobPtr &b)
        {
            return a.cur == b.cur;
        }
        friend bool operator!=(const BlobPtr &a, const BlobPtr &b)
        {
            return a.cur != b.cur;
        }
        friend bool operator<(const BlobPtr &a, const BlobPtr &b)
        {
            return a.cur < b.cur;
        }
        friend bool operator>(const BlobPtr &a, const BlobPtr &b)
        {
            return a.cur > b.cur;
        }
        
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



int main(int argc, const char * argv[]) {
    
    Practise_16_12::test();
    
    return 0;
}
