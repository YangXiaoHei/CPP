#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

void print_vec(const vector<int> &vec)
{
    for (auto i : vec)
        printf("%d ",i);
    cout << endl;
}

int main()
{
    vector<int> vec;
    vec.insert(vec.end(), 10, 9);
    print_vec(vec); 

    vec.insert(vec.begin(), 100);
    print_vec(vec);

    int arr[] = { 1, 2, 3, 4, 5 };
    vec.insert(vec.begin(), begin(arr), end(arr));
    print_vec(vec);

    list<double> list = { 2.1, 3.2, 4.3 };
    vec.insert(vec.end(), list.begin(), list.end());
    print_vec(vec);

    vec.insert(vec.end(), { 100, 101, 102, 103 });
    print_vec(vec);
}


