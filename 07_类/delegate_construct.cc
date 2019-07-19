#include <iostream>

using namespace std;

struct A {
    int a;
    int b;
    int c;
    A(int aa, int bb, int cc) : a(aa), b(bb), c(cc) {
        cout << "more param construct" << endl;
    }
    A() : A(0, 0, 0) {
        cout << "default construct" << endl;
    }
};

int main()
{
    A a;
}
