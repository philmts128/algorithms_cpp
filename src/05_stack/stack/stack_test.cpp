#include <iostream>
#include <string>
#include <ctime>
using namespace std;

#include "stack.h"

void int_test()
{
    pm::stack<int> stck;

    cout << "push: ";
    for (int i = 0; i < 10; ++i) {
        int x = i*2;
        cout << x << ' ';
        stck.push(x);
    }

    cout << "\npop: ";
    while (!stck.is_empty()) {
        cout << stck.top() << ' ';
        stck.pop();
    }
}

int main()
{
    int_test();

    printf("\n\n");
    return 0;
}
