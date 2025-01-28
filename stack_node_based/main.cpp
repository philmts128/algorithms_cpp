#include <iostream>
using namespace std;

#include "stack.h"

int main()
{
    pm::stack<int> nums;
    for (int i = 0; i <= 10; ++i)
        nums.push(i);

    while (!nums.empty())
        cout << nums.pop() << " ";

    return 0;
}
