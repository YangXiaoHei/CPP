#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    ofstream out;
    out.open(argv[1], ofstream::app);
    out << "hello world";
    out.close();
}
