#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = static_cast<vector<int>>(10);
    for (auto i : v)
        cout << i << endl;
}
