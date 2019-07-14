#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name;
    string address;
    Person (const string &n, const string &a) : name(n), address(a) {}

    string getName() const;
    string getAddress() const;
};

string Person::getName() const 
{
    return name;
}

string Person::getAddress() const
{
    return address;
}

int main()
{
    Person p("haha", "xixi");
    cout << p.getName() << " " << p.getAddress() << endl;
}
