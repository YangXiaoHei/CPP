#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

struct PersonInfo {
    friend ostream& operator<<(ostream &os, const PersonInfo &p);
    string name;
    vector<int> phones;
};
ostream& operator<<(ostream &os, const PersonInfo &p) {
    os << "name : " << p.name << endl;
    os << "\t";
    for (auto i : p.phones)
        os << i << " ";
    os << endl;
    return os;
}

bool is_valid_num(const string &phone)
{
    return phone.size() && phone[0] != '1';
}

int main(int argc, char *argv[])
{
    ifstream reader(argv[1]);
    if (!reader) {
        cout << "打开文件失败" << endl;
        exit(1);
    }

    vector<PersonInfo> vec;
    string line;
    while (getline(reader, line)) {
        PersonInfo p;

        istringstream is(line);
        is >> p.name;

        string phone;
        while (is >> phone) {
            int number = (int)strtol(phone.c_str(), NULL, 10);
            p.phones.push_back(number);
        }
        vec.push_back(p);
    }
    for (auto i : vec)
        cout << i << endl;

    ostringstream bad_numbers;
    for (auto &pinfo : vec) {
        for (auto phone : pinfo.phones) {
            if (!is_valid_num(to_string(phone)))
                bad_numbers << phone << " ";
        }
    }
    cout << bad_numbers.str() << endl;
}
