#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "linked_list.h"


int main()
{
    pm::linked_list<int> l;
    for (int i = 1; i <= 10; ++i)
        l.push_back(i);

    l.insert(999, 8);
    l.insert(1000, 0);
    l.print();

    pm::linked_list<string> fruits;
    fruits.push_back("apple");
    fruits.push_back("watermelon");
    fruits.push_back("guava");

    fruits.insert("strawberry", 0);
    fruits.insert("orange", 1);

    fruits.print();


    return 0;
}
