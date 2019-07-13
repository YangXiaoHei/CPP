#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << 1 << 2 << endl;

    vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(i);

    for (auto i : vec)
        cout << i << endl;

    return -1;
}
