#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1(9);

    for (auto i : v1)
        cout << i << endl;

    vector<int> v2(10, 9);
    for (auto i : v2)
        cout << i << endl;

    vector<int> v3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto i : v3)
        cout << i << endl;
}

