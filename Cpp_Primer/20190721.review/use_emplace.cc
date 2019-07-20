#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

struct A {
    const char *ptr;
    double d;

    A (const char *p, double dd) : ptr(p), d(dd) {}
};

int main()
{
    vector<A> vec;

    vec.insert(vec.end(), A("1000", 1.1));
    vec.emplace(vec.end(), "1000", 1.1);

    vec.emplace_back("11111", 9.9);

    deque<A> deq;
    deq.emplace_front("xixixixi", 111);
}
