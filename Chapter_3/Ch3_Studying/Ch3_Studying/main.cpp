//
//  main.cpp
//  Ch3_Studying
//
//  Created by YangHan on 2018/2/28.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void definitionAndInitilizeString() {
    string s1;
    string s2 = s1;
    string s3 = "hiya";
    string s4(10, 'c');
    string s5(s3);
    string s6("yanghan");
}

void readStringUtilSpace() {
    string word;
    // 遇到空格就停止读取
    while (cin >> word)
        cout << word << endl;
}
void readStringUtilCarriage() {
    string line;
    // 遇到回车就停止读取
    while (getline(cin, line))  // 回车虽然被读到了，但是被丢弃
        cout << line << endl;
}

void pointerAndArray() {
    {
        string nums[] = {"one", "two", "three"};
        string *p = &nums[0];
        cout << sizeof(nums) << endl;
        string *p2 = nums; // 等价于 p2 = &nums[0]
    }
    {
        int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        auto ia2 = ia;
        auto ia3 = &ia[0];
        
        /**
         *  使用 auto 时，数组退化为指针
            使用 decltype 时，还是个数组
         */
        decltype(ia) ia4 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//        ia4 = ia2;  不能把整型指针赋值给整型数组
        ia4[1] = 3;
        for (int i = 0; i < 10; i++) {
            cout << ia4[i] << " ";
        }
        cout << endl;
    }
    {
        /**
         *  标准库函数 begin() 和 end()
         */
        int ia[] = {0, 1, 2, 3, 4, 5, 6};
        int *b = begin(ia);
        int *e = end(ia);
        while (b != e)
            cout << *(b++) << endl;
    }
    
}

void initializeVectorWithArray() {
    int int_arr[] = {1, 2, 3, 4, 5, 6, 7};
    vector<int> ivec(begin(int_arr), end(int_arr));
    for (int i = 0; i < ivec.size(); i++) {
        cout << ivec[i] << endl;
    }
}

int main(int argc, const char * argv[]) {
    initializeVectorWithArray();
    return 0;
}
