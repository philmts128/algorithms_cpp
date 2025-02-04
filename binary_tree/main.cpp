#include <iostream>
using namespace std;

#include "binary_tree.h"

int main()
{
    pm::binary_tree<int> tree;
    tree.insert(1);
    tree.insert(3);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.insert(9);
    tree.print();
    return 0;
}
