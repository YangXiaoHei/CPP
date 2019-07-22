#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream reader(argv[1]);
    if (!reader) {
        cout << "打开文件失败" << endl;
        _exit(1);
    }

    /*
     * reader << "xixixix";
     * if (!reader) {
     *     cout << "流状态失败" << endl;
     *     _exit(1);
     * }
     */

    cout << unitbuf;

    string buf;
    while (reader >> buf)
        cout << buf << endl;
    reader.close();

    ofstream out(argv[1], ofstream::app | ostream::out);
}
