#include <iostream>
#include <string>
using namespace std;

#include "queue.h"
#include "doubly_linked_list.h"

void string_test()
{
    pm::queue<string> ql;
    string langs[]  { "java", "python", "c++", "go" };

    cout << "\n\nenqueue: ";
    for (string s : langs) {
        cout << s << " - ";
        ql.enqueue(s);
    }

    cout << "\ndequeue: ";
    while (!ql.is_empty()) {
        cout << ql.front() << " - ";
        ql.dequeue();
    }
}

void int_test()
{
    pm::queue<int> qn;

    cout << "enqueue: ";
    for (int i = 0; i < 10; ++i) {
        int x = i*2;
        cout << x << ' ';
        qn.enqueue(x);
    }

    cout << "\ndequeue: ";
    while (!qn.is_empty()) {
        cout << qn.front() << ' ';
        qn.dequeue();
    }
}

int main()
{
    int_test();
    string_test();



    printf("\n\n");
    return 0;
}
