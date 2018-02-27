//
//  main.cpp
//  Ch2_Studying
//
//  Created by YangHan on 2018/2/26.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include "Tool.hpp"

using namespace std;

/**
 *  C++标准规定的尺寸的最小值
 
    bool        未定义
    char        8 bit
    wchar_t     16 bit
 
    char16_t    16 bit
    char32_t    32 bit  ---> 为 Unicode 字符集服务
 
    short       16 bit
    int         16 bit  ---> int 至少和 short 一样大
 
    long        32 bit
    long long   64 bit  ---> long 至少和 int 一样大
                        ---> long long 至少和 long 一样大
    float       6 位有效数字
    double      10 位有效数字
    long double 10 位有效数字
 
 */

void displayCurrentBits() {
    cout << (sizeof(bool) << 3) << endl;
    cout << (sizeof(char) << 3) << endl;
    cout << (sizeof(wchar_t) << 3) << endl;
    cout << (sizeof(char16_t) << 3) << endl;
    cout << (sizeof(char32_t) << 3) << endl;
    cout << (sizeof(short) << 3) << endl;
    cout << (sizeof(int) << 3) << endl;
    cout << (sizeof(long) << 3) << endl;
    cout << (sizeof(long long) << 3) << endl;
    cout << (sizeof(float) << 3) << endl;
    cout << (sizeof(double) << 3) << endl;
    cout << (sizeof(long double) << 3) << endl;
}

/**
 *  含有无符号类型的表达式
 
 */
void unsignedAndSigned() {
    unsigned u = 10;
    int i = -42;
    cout << "i      =   "; int_binary_str(i);
    cout << "u      =   "; int_binary_str(u);
    cout << "i + u  =   "; int_binary_str(u + i);
    cout << "i + u  =   " << i + u << endl;
    
    cout << endl;
    
    unsigned u1 = 42, u2 = 10;
    cout << "u2       =   "; int_binary_str(u2);
    cout << "u1       =   "; int_binary_str(u1);
    cout << "u2 - u1  =   "; int_binary_str(u2 - u1);
    cout << "u2 - u1  =   " << u2 - u1 << endl;
}

/**
 *  转义序列
 */
void escapeSequence() {
    cout << "Hi \x4dO\115!\n";
    /**
     *  \x 后跟着 1 或多个 十六进制数字
        或者 \ 后跟着 1, 2, 3 个八进制数字
     */
    cout << "\1234" << endl;
    // 如果反斜线后面跟着的八进制数字超过 3 个，只有前3个数字与 \ 构成转义序列
}

void literal() {
    /**
     
        字符和字符串字面量
     
     *  u   Unicode 16 字符           char16_t
        U   Unicode 32 字符           char32_t
        L   w宽字符                    char_t
        u8  UTF-8(仅用于字符串字面量)    char
     
     
        整型字面量
     
        u or U
        l or L
        ll or LL
     
        浮点型字面值
     
        f or F   float
        l or L   long double
     */
}

/**
 *  如果列表初始化用的初始值类型和声明不一致，编译器报错
 */
void listInitialized() {
    { int units_sold = 0; }
    { int units_sold = {0}; }
    { int units_sold(0); }
    { int units_sold{0}; }
    
    long double d = 3.1415926536;
    
//    int a{d};  // 编译器报错
    int a = d;  // 编译器不报错
//    double dd{d};  // 编译器报错
    
    long l = 123;
//    int b{l};  // 编译器报错
    
    float f = 3.14f;
//    int i{f};  编译器报错
}

/**
 *  引用
 */
void reference() {
    // 引用必须被初始化
    int ival = 1024;
    int &refVal = ival;
//    int &refVal2;
}

/**
 *  指针
 */
void pointer() {
    
    int a = 1;
    int *p = &a;
    int &r = *p;
    
    r = 100;
    
    cout << a << endl;
}

/**
 *  指向指针的引用
 */
void relPointer() {
    int i = 42;
    
    int *p;
    
    int *&r = p;
    
    r = &i;
    
    *r = 0;
    
    cout << i << endl;
}

/**
 *  const 限定符
 */
int get_size() { return 1; }
void constSpecifier() {
    const int j = get_size();  // 运行时初始化
    const int i = 42;          // 编译时初始化
//    const int k; const 对象必须被初始化
}

void constReference() {
    int a = 10, b = 20;
    
    // 不能通过常量引用去修改 a 的值
    const int &r = a;
    
    // 常量引用可以用字面量初始化，也可以用表达式初始化
    const int &r1 = 42;   // 绑定到了临时量上
    const int &r2 = a * b;
//    int &r3 = r1;
    
    {
        int i = 42;
        int &r1 = i;
        const int &r2 = i;
        r1 = 0;
//        r2 = 0;   不允许通过 r2 修改 i 的值
    }
    
    {
        int i = 10;
        int *const p = &i;
//        int *const p1; 常量指针必须被初始化
    }
}

void constexprAndConstExpression() {
    const int max_files = 20;           // 常量表达式
    const int limit = max_files + 1;    // 常量表达式
    int staff_size = 27;                // 非常量表达式
    const int sz = get_size();          // 非常量表达式
    
    /**
     *  将变量声明为 constexpr 类型以便由编译器来验证变量的值是否是一个常量表达式
     
        声明 constexpr 时用到的类型必须有所限制，比如 ( 字面值类型 literal type ) 算术类型，引用，指针
     
        尽管指针和引用都能定义成 constexpr， 但它们的初始值受到严格限制，一个 constexpr 指针的初始值必须是 nullptr 或者 0
        或者存储与某个固定地址中的对象
     
        函数体内定义的变量一般来说并非存放在固定的地址中，因此 constexpr 不能指向这样的变量，
        而定义于所有函数体之外的对象其地址固定不变，能用来初始化 constexpr 指针
        在函数体内定义的超出函数本身的变量，也拥有固定地址， constexpr 也能指向这样的对象
     */
    {
        constexpr int mf = 20;
        constexpr int limit = mf + 1;
//        constexpr int sz = get_size();  // 只有当 size 是一个 constexpr 函数时才是一条正确的声明语句
    }
    
    /**
     *  ⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️
     */
    const int *p = nullptr;
    constexpr int *q = nullptr;
    
    // p 是指向常量的指针
    // q 是常量指针
}

int j = 0;
constexpr int i = 42;           // i 是整型常量
constexpr const int *p = &i;    // p 是常量指针，指向整型常量 i
constexpr int *p1 = &j;         // p1 是常量指针，指向整型 j


/**
 *  ⚠️⚠️⚠️⚠️⚠️⚠️⚠️
 
    const char *cstr 是对 const pstring cstr 的错误理解
 */
void pointer_const_alias() {
    typedef char * pstring;
    const pstring cstr = 0;  // cstr 是指向 char 的常量指针
    const pstring *ps;       //
}
void aliasConstTest() {
    
    typedef char *pstring;
    
    pstring str = (char *)calloc(4, sizeof(char));
    str[0] = '1';
    str[1] = '2';
    str[2] = '3';
    str[3] = '\0';
    
    pstring str1 = (char *)calloc(4, sizeof(char));
    str1[0] = '4';
    str1[1] = '5';
    str1[2] = '6';
    str1[3] = '\0';
    
    pstring str2 = (char *)calloc(4, sizeof(char));
    str2[0] = '7';
    str2[1] = '8';
    str2[2] = '9';
    str2[3] = '\0';
    
    pstring *ps = (pstring *)calloc(3, sizeof(pstring));
    ps[0] = str;
    ps[1] = str1;
    ps[2] = str2;
    
    const pstring *ps1 = ps;
//    ps1[0] = nullptr; 指向常量的指针
    
    pstring * const ps2 = ps;
    ps2[0] = nullptr;   // 常量指针
    
    if (ps2[0])  cout << ps2[0] << endl;
    if (ps2[1])  cout << ps2[1] << endl;
    if (ps2[2])  cout << ps2[2] << endl;
}

void auto_type() {
    /**
     *  auto 会忽略掉顶层 const 而留下底层 const
     */
    
    int i = 0;
    
    const int ci = i, &cr = ci;
    
    auto b = ci;    // b 是一个整数
    auto c = cr;    // c 是一个整数
    auto d = &i;    // d 是一个整型指针
    auto e = &ci;   // e 是一个指向整数常量的指针
    
    /**
     *  如果希望推断出的 auto 类型是一个顶层 const 需要明确指出
     */
    const auto f = ci;
    auto &g = ci;   // 整型常量引用
//    auto &h = 42;   // auto 不能推断出顶层 const，因此不能为非常量引用绑定字面量
    const auto &j = 42; // 明确指出需要推断出常量引用，因此可以绑定字面量
    
}










int main(int argc, const char * argv[]) {
    aliasConstTest();
    return 0;
}
