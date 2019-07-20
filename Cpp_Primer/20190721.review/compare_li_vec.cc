#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = { 1, 2, 3, 4, 5 };
    list<int> lis = { 1, 2, 7 };

    int result = vector<int>(lis.begin(), lis.end()) > vec;
    cout << result << endl;

}
