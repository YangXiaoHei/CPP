#include <iostream>
#include <vector>

using namespace std;

struct A {
    string c;
    A (const string &s) : c(s) {}
    void add(const A &a) const {
        cout << "haha" << endl;
    }
};

int main()
{
    A a("1234");

    a.add(string("1234"));
}
