#include <iostream>
#include <unistd.h>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    string str = "yanghan\t23\t60\nlijie 25 80\nyuxiaokun 39 60";

    istringstream is(str);
    string line;
    string name;
    string age;
    string weight;
    while (getline(is, line)) {
        istringstream record(line);
        record >> name >> age >> weight;
        cout << "name :" << name << endl; 
        cout << "age : " << age << endl;
        cout << "weight :" << weight << endl; 
        cout << endl;
    }
}
