#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int ival = 1;
    int *p = NULL;
    p = &ival;

    int &iref = *p;
    iref = 99;

    cout << ival << endl;
}
