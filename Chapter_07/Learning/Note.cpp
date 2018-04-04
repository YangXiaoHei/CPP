#include <string>

//this 是一个常量指针

class A {
    void fun() const; //const 函数的 const 修饰 this 指针是指向常量的指针
    // 但并不是说 const 函数内不能修改任何类的成员，比如 mutable 修饰的就仍然可以被修改
};

class B {
    mutable int a;
    void fun() const {
        a++; // a 可以被修改
    }
};

class C {
    void fun() const {  // const 函数内不能调用非 const 函数
//        foo();
    }
    void foo() {
        
    }
};

// 可以在类外部定义成员函数

// 返回一个 this，*this 对象，从 const 函数返回的 *this 是一个常量引用，const 和非 const 函数可以是重载关系

// 如果非成员函数是类接口的组成部分，那么这些函数的声明应该与类在同一个头文件内

// 合成的默认构造函数  ---> 编译器自己给你加的

// = default

// class 和 struct 区别 class 中出现访问说明符前都是私有，struct 中出现前都是公有

// 友元函数必须在类内声明一次，在类外部也声明一次，有的编译器并未强制要求这么做，但最好这么做

// 定义在类内部的成员函数是内联的，定义在类外部的可以手动添加 inline 让其内联

// 友元类，友元函数，友元和重载函数

// 友元声明和作用域
struct X {
    friend void f() { /* 友元函数可以定义在类的内部 */ }
    X() { f(); }
    void g();
    void h();
};
void X::g() { return f(); }
void f();  // 声明了定义在 X 内的函数
void X::h() { return f(); }  // 直到此时，f() 的声明才在作用域中，才可以被使用

// 名字查找与类的作用域

/*
 *      定义在类内部的成员函数，解析其中名字的方式
 *      首先，编译成员的声明
 *      直到类全部可见后才编译函数体
 */
typedef double Money;
std::string bal;
class Account {
public:
    Money balance() { return bal; } // 编译器先编译函数声明，看到了 Money，然后去前面找，直到在类外面找到了
    // typedef 语句，然后继续编译 Money bal 这个类成员，最后编译 balance() 函数体，所以在函数体中返回的是类成员 bal 而不是类外部的 string bal
private:
    Money bal;
};

// 在类中，如果成员使用了外层作用域中的某个名字，而该名字代表一种类型，则类不能再之后重新定义该名字
namespace YH {
    typedef double Money;
    class Account {
    public:
        Money balance() { return bal; }
    private:
        typedef char * Money;
        Money bal;
    };
}

// 看下面几个例子
int height;  // 1
namespace YH2  {
    int height; // 2
    class Screen {
    public:
        typedef std:: string::size_type pos;
        void dummy_fcn_1(pos height) {
            cursor = width * height; // 参数覆盖的
        }
        void dummy_fcn_2(pos);
        void dummy_fcn_3(pos);
        void dummy_fcn_4(pos);
        void dummy_fcn_5(pos);
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
    };
    void Screen::dummy_fcn_5(pos height) {
        cursor = width * this->height; // 类成员
    }
    void Screen::dummy_fcn_2(pos ht) {
        cursor = width * height; // 类成员
    }
    void Screen::dummy_fcn_3(pos height) {
        cursor = width * YH2::height;  // 2
    }
    void Screen::dummy_fcn_4(pos height) {
        cursor = width * ::height;  // 1  :: 表示全局 namespace
    }
}

// 类成员函数定义在类外部，使用之前声明过的函数
namespace YH3 {
    int height;
    class Screen {
    public:
        typedef std:: string::size_type pos;
        void setHeight(pos);
        pos height = 0;
    };
    Screen::pos verify(Screen::pos);
    void Screen::setHeight(pos var) {
        // var : 参数
        // height : 类成员
        // verify : 全局函数
        height = verify(var);
    }
}







