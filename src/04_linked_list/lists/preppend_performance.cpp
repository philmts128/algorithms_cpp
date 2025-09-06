/*
 * Comparação de performance entre vetor e lista (com alocação em pool), quando inserimos elementos no inicio
 * Autor: Philippe Matias
*/

#include <iostream>
using namespace std;

#include "vector.h"
#include "fast_linked_list.h"
#include "timer.h"


/*---------------------------------------------*/
int main()
{
    pm::vector<int> v;
    pm::fast_linked_list<int> l;
    pm::timer timer;

    timer.measure(1, [&](){
        for (int i = 0; i < 500000; ++i)
            v.preppend(i); //O(n)
    });

    v.clear();
    cout << "vetor: " << timer.get_result();

    timer.measure(1, [&](){
        for (int i = 0; i < 500000; ++i)
            l.preppend(i); //O(1), mas com operação muito lenta que precisou ser otimizada
    });

    cout << "\nlista: " << timer.get_result();
    l.clear();

    printf("\n\n");
    return 0;
}
