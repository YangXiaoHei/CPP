#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> vec = { 1, 2, 3, 4, 5 };
    if (!vec.empty()) {
        auto v = vec.front();
        cout << v << endl;

        auto &m = vec.back();
        m = 100;

        *vec.begin() = 99;

        auto e = vec.end();
        *(--e) = 98;
    }

    for (auto i : vec)
        cout << i << " ";
    cout << endl;
}
