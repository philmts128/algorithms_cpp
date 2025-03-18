/**
 * Testa performance de algoritmo de inserir em vetores dinâmicos.
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
    pm::vector<int> fast_ints;
    pm::slow_vector<int> slow_ints;
    pm::timer timer;


    timer.measure(2, [&](){
        slow_ints.clear();
        for (int i = 0; i < 50000; ++i) {
            slow_ints.append(i);
        }
    });

    cout << "slow vector: " << timer.get_result() << '\n';

    timer.measure(2, [&](){
        fast_ints.clear();
        for (int i = 0; i < 50000; ++i) {
            fast_ints.append(i);
        }
    });

    cout << "fast vector: " << timer.get_result() << '\n';

    cout << "\n\n";
    return 0;
}
