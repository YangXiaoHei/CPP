#include <iostream>
#include <string>

using namespace std;

class Y;
class X {
    Y *y;
};

class Y {
    X x;
};

int main()
{
    X x;
    Y y;
}
