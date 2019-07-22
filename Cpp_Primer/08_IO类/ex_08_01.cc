#include <iostream>
#include <string>
#include <fstream>

using namespace std;

istream& read_file(istream &file_stream)
{
    string s;
    while (file_stream >> s) {
        cout << s << endl;
    }
    file_stream.clear();
    return file_stream;
}

int main()
{
    ifstream reader("test_data");
    read_file(reader); 
}
