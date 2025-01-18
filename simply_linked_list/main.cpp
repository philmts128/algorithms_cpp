/**
 * Teste de lista simplesmente encadeada
 * Autor: Philippe Matias
*/

#include <iostream>
using namespace std;

#include "linked_list.h"

int main()
{
    pm::linked_list<int> even_ints;

    for (int i = 0; i <= 10; ++i)
        even_ints.push_back(i);

    pm::linked_list<int> other = even_ints;

    cout << "Lista originl: ";
    other.print();

    cout << "Depois de apagar 2 primeiros items: ";
    other.pop_front();
    other.pop_front();
    other.print();

    cout << "Depois de add. 5 items no fim e a 500 no primeiro: ";
    other.push_back(999);
    other.push_back(1250);
    other.push_front(500);
    other.print();

    cout << "\n\n";
    return 0;
}
