#include <iostream>
#include <vector>

using namespace std;

struct A {
    char str[10000];
};

int main()
{
    {
        vector<A> vec;
        cout << vec.max_size() << endl;
    }
    {
        vector<long> vec;
        cout << vec.max_size() << endl;
    }
    {
        vector<char> vec;
        cout << vec.max_size() << endl;
    }
    {
        vector<int> vec;
        cout << vec.max_size() << endl;
    }
}
