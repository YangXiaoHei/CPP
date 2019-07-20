#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    vector<double> vec = { 1, 2, 3, 4, 5 };
    list<int> lis(vec.begin(), vec.end());

    for (auto i : lis)
        printf("%d ", i);
    cout << endl;



}
