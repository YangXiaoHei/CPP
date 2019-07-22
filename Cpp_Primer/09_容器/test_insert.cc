#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    vector<int> vec = { 1, 2, 3, 4, 5 };
    auto it = vec.begin();
    vec.insert(it, 0);

    vec.insert(vec.end(), 3, 9);

    list<int> l = { 100, 99, 98 };
    vec.insert(vec.end(), l.begin(), l.end());

    for (auto i : vec)
        cout << i << " ";
    cout << endl;
}
