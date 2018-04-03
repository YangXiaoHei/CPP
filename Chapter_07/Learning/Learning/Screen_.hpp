//
//  Screen_.hpp
//  Learning
//
//  Created by YangHan on 2018/4/3.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#ifndef Screen__hpp
#define Screen__hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

struct X {
    friend void f() { /* 友元函数可以定义在类的内部 */ }
    //        X() { f(); }
    void g();
    void h();
};
//    void X::g() { return f(); }
void f();
void X::h() { f(); }

namespace YH {
    using namespace std;

    // Screen
    class Screen {
        friend class WindowManager;
    public:
        typedef string::size_type pos;
        
        Screen() = default;
        Screen(pos w, pos h) : width(w), height(h), contents(w * h, ' ') {}
        Screen(pos w, pos h, char c) : width(w), height(h), contents(w * h, c) {}
        const Screen& display(ostream& os) const {
            do_display(os);
            return *this;
        }
        Screen& display(ostream& os) {
            do_display(os);
            return *this;
        }
    private:
        pos height, width, cursor;
        string contents;
        
        void do_display(ostream& os) const {
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    os << contents[i * width + j];
                }
                os << endl;
            }
        }
    };
    
    // WindowManager
    class WindowManager {
    public:
        using scrIdx = vector<Screen>::size_type;
        vector<Screen> screens{ Screen(24, 80, ' ') };
        void clear(scrIdx i) {
            Screen &s = screens[i];
            s.contents = string(s.width * s.height, ' ');
        }
    };
}

#endif /* Screen__hpp */
