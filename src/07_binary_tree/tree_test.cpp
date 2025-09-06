#include <iostream>
#include <string>
using namespace std;

#include "binary_tree.h"


int main()
{
    pm::binary_tree<int> n;
    n.insert(-20);
    n.insert(19);
    n.insert(-18);
    n.insert(17);
    n.insert(-16);
    n.insert(21);
    n.insert(-22);
    n.insert(23);
    n.insert(-24);

    cout << "max: " << n.max() << '\n';
    cout << "min: " << n.min() << '\n';

    n.print();

    cout << "\n\n";
    return 0;
}
