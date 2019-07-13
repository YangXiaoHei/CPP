#include <iostream>
#include <vector>

using namespace std;

void print(int (*arr)[10])
{
    for (int i = 0; i < 10; i++)
        cout << *((int *)arr + i) << endl;
}

int main()
{
    int arr[10] = { 0 };
    for (int i = 0; i < 10; i++)
        arr[i] = i;
    print(&arr); 
}
