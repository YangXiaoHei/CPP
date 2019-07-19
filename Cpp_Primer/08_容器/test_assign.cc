#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1 = { 1, 2, 3, 4, 5, 6 };
    vector<int> v2 = { 7, 8, 9 };

    // v2.assign(v1.begin(), v1.end());
    
    v2.assign({ 10, 11, 12 });

    v2.assign(10, 99);

    for (auto i : v2)
        cout << i << endl;
}
