#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream reader(argv[1]);
    if (!reader) {
        cout << "open fail!" << endl;
        exit(1);
    }

    string buf;
    string word;
    while (reader >> word)
        buf += word + " ";

    cout << buf << endl;
}
