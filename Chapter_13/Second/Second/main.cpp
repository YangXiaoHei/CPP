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

using namespace std;

namespace YH {
    class MyStr {
        friend ostream& operator<<(ostream &os, const MyStr& m);
    public:
        MyStr(const char *s) : val(s) { cout << "constrctors" << endl; }
        MyStr(const MyStr& m) : val(m.val) { cout << "copy constrctors" << endl; }
    private:
        string val;
    };
    ostream& operator<<(ostream &os, const MyStr& m) {
        os << m.val;
        return os;
    }
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

namespace Practise_13_03 {
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



int main(int argc, const char * argv[]) {

    Practise_13_03::test();
    
    
    return 0;
}
