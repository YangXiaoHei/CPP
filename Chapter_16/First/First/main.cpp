//
//  main.cpp
//  First
//
//  Created by YangHan on 2018/4/21.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <vector>

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

int main(int argc, const char * argv[]) {
    
    Practise_16_03::test();
    
    return 0;
}
