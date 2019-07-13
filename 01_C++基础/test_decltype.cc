#include <iostream>

using namespace std;

int main()
{
    int a = 1;

    decltype((a)) c = a;
    c = 99;
    cout << a << endl;

    int *p = &a;
    decltype(*p) d = a;
    d = 100;
    cout << a << endl;
}
