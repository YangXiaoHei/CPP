#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream reader(argv[1]);
    if (!reader) {
        cout << "打开文件失败" << endl;
        exit(1);
    }

    vector<int> vec;
    string line;
    string num;
    while (getline(reader, line)) {
        istringstream is(line);
        while (is >> num) {
            long n = strtol(num.c_str(), NULL, 10);
            vec.push_back(n);
        }
    }
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
}
