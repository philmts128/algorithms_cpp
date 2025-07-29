/**
 * Compara performance de inserção no fim (O(1)) e no início (O(n)) de um vetor.
 * Autor: Philippe Matias
 */

#include <iostream>
using namespace std;

#include "timer.h"
#include "slow_vector.h"
#include "vector.h"


/*-----------------------------*/
int main()
{
    pm::vector<int> v1;
    pm::vector<int> v2;
    pm::timer t;

    t.measure(2, [&]() {
        for (size_t i = 0; i < 300000; ++i)
            v1.append(i);
    });

    cout << "| append time: " << t.get_result() << '\n';

    t.measure(2, [&]() {
        for (size_t i = 0; i < 300000; ++i)
            v2.preppend(i);
    });

    cout << "| preppend time: " << t.get_result() << '\n';



    cout << "\n\n";
    return 0;
}
