#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    cin >> i;
    if (cin.eof())
        cout << "eof" << endl;
    if (cin.good())
        cout << "good" << endl;
    if (cin.fail())
        cout << "fail" << endl;
    if (cin.bad())
        cout << "bad" << endl;

}
