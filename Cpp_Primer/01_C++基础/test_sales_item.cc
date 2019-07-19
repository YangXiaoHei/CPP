#include <iostream>
#include "src/1/Sales_item.h"

using namespace std;

int main(int argc, char *argv[])
{
    Sales_item book;

    while (cin >> book)
        cout << book << endl;
    return 0;
}
