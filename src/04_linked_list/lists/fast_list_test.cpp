#include <iostream>
#include <string>
using namespace std;

#include "fast_linked_list.h"


int main()
{
    pm::fast_linked_list<string> bands;

    bands.append("Alice in Chains");
    bands.append("Opeth");
    bands.append("Rotting Christ");
    bands.preppend("Travis");
    bands.preppend("Keane");
    bands.preppend("Garbage");

    bands.print();

    auto bands1 = bands;
    bands1.remove_back();
    bands1.remove_front();
    bands1.remove_back();
    bands1.remove_front();

    printf("\n\n");
    for (const auto& b : bands1)
        std::cout << b << '\n';

    printf("\n\n");
    return 0;
}
