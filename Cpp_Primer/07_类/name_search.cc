#include <iostream>

using namespace std;

int height = 2;
struct Screen {
    int dummy_fun(int height)
    {
        return ::height * 2;
    }
    int height = 3;
};

int main()
{
    Screen s;
    cout << s.dummy_fun(4) << endl;
}
