#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = { 1, 2, 3, 4, 5 };
    vector<int> newvec;

    // 迭代器
    newvec.assign(vec.begin(), vec.end());

    for (auto i : newvec) cout << i << endl;

    // (n, t)
    newvec.assign(10, 5);
    for (auto i : newvec) 
        cout << i << " ";
    cout << endl;

    // 花括号
    newvec.assign({ 100, 101, 102 });
    for (auto i : newvec)
        printf("%d ", i);
    cout << endl;
}
