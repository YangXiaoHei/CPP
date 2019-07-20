#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct A {
    string str;
    const char *ptr;
    double d;
    int i;

    A (const string &s, const char *p, double dd, int ii) : str(s), ptr(p), d(dd), i(ii) { }
};

int main()
{
    vector<A> vec;

    vec.push_back(A("haha", "xixi", 12, 3));
    vec.emplace_back("haha", "xixi", 12, 3);
}
