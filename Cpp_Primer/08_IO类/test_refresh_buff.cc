#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    cout << "haha" << endl;
    cout << "heiihei" << flush;
    cerr << "xixixix";
    cout << "hello world" << ends;
    _exit(1);
}
