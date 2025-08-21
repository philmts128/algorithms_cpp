#include <iostream>
using namespace std;

#include "fast_linked_list.h"
#include "doubly_linked_list.h"
#include "timer.h"


int main()
{
    pm::timer tm;
    pm::fast_linked_list<int> fl;
    pm::doubly_linked_list<int> sl;

    tm.measure(2, [&](){
        for (int j = 0; j < 10; ++j)
        {
            for (int i = 0; i < 10000000; ++i)
                sl.append(i);
            sl.clear();
        }
    });

    cout << "time [slow list]: " << tm.get_result() << "\n\n";

    tm.measure(2, [&](){
        for (int j = 0; j < 10; ++j)
        {
            for (int i = 0; i < 10000000; ++i)
                fl.append(i);
            fl.clear();
        }
    });

    cout << "time [fast list]: " << tm.get_result();

    printf("\n\n");
    return 0;
}
