#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    int i;
    cout << "please input a number";
    cin >> i;
    cout << i;
    _exit(1);
}
