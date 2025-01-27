#include <iostream>
using namespace std;

#include "queue.h"

int main()
{
    pm::queue<int> nums;

    for (int i = 1; i <= 10; ++i)
        nums.enqueue(i);

    while (!nums.empty())
        cout << nums.dequeue() << " ";

    return 0;
}
