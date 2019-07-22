#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    cout << unitbuf;
    ifstream reader;
    reader.open(argv[1]); 
    if (!reader) {
        cout << "文件打开失败!";
        _exit(1);
    }

    cout << "文件打开成功";
}
