#include <iostream>
using namespace std;

#include "vector.h"

int main()
{
    ph::vector nums;

    nums.push_back(11);
    nums.push_back(22);
    nums.push_back(33);
    nums.push_back(44);
    nums.push_back(55);

    for (int i = 0; i < nums.size(); ++i)
        cout << nums.at(i) << " ";

    return 0;
}
