//
//  Screen.hpp
//  Learning
//
//  Created by YangHan on 2018/4/3.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#ifndef Screen_hpp
#define Screen_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Screen {
public:
    // 内置类型
    typedef std::string::size_type pos;
    
    // 构造函数
    Screen() = default;
    Screen(pos w, pos h) : height(h), width(w), contents(w * h, ' ') {}
    Screen(pos w, pos h, char c) : height(h), width(w), contents(w * h, c) {}
    
    // 返回的是一个 const 引用
    const Screen& display(ostream& os) const { // const 修饰 this，所以 *this 是一个常量对象
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                os << contents[i * width + j] << " ";
            }
            os << endl;
        }
        return *this; // 这里返回的是常量引用
    }
    
    // 移动光标
    Screen& move(pos r, pos c) {
        cursor = r * width + c;
        return *this;
    }
    
    // 设置光标处字符
    Screen& set(char c) {
        contents[cursor] = c;
        return *this;
    }
private:
    pos height, width, cursor;
    string contents;
};

#endif /* Screen_hpp */
