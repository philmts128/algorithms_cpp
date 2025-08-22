#include <iostream>
#include <string>
using namespace std;

#include "stack.h"

void string_test()
{
    pm::stack<string> sl;
    string langs[]  { "java", "python", "c++", "go" };

    cout << "\n\npush: ";
    for (string s : langs) {
        cout << s << " - ";
        sl.push(s);
    }

    cout << "\npop: ";
    while (!sl.is_empty()) {
        cout << sl.top() << " - ";
        sl.pop();
    }
}

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
    string_test();

    printf("\n\n");
    return 0;
}
