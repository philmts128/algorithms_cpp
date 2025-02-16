#include <iostream>
#include <string>
using namespace std;

#include "binary_tree.h"

int main()
{
    pm::binary_tree<int> t;
    t.insert(5);
    t.insert(7);
    t.insert(9);
    t.insert(2);
    t.insert(8);
    t.insert(999);
    t.insert(120);
    t.insert(23);
    t.print();

    pm::binary_tree<string> fruits;
    fruits.insert("apple");
    fruits.insert("pear");
    fruits.insert("tomato");
    fruits.insert("grape");
    fruits.insert("watermelon");
    fruits.insert("banana");
    fruits.print();

    printf("\n\n");
    return 0;
}
