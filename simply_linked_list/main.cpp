/**
 * Teste de lista simplesmente encadeada
 * Autor: Philippe Matias
*/

#include <iostream>
using namespace std;

#include "linked_list.h"

int main()
{
    pm::linked_list<int> ints;

    for (int i = 0; i <= 10; ++i)
        ints.push_back(i);

    pm::linked_list<int> other = ints;

    cout << "Utimo: " << other.last() << '\n';
    cout << "Lista originl: ";
    other.print();

    other.pop_front();
    other.pop_front();
    cout << "Utimo: " << other.last() << '\n';
    cout << "Depois de apagar 2 primeiros items: ";
    other.print();

    other.push_back(999);
    other.push_back(1250);
    other.push_front(500);
    cout << "Utimo: " << other.last() << '\n';
    cout << "Depois de add. 2 items no fim e a 500 no primeiro: ";
    other.print();

    ints = other;
    ints.pop_back();
    ints.pop_back();
    ints.push_back(44);
    cout << "Utimo: " << ints.last() << '\n';
    cout << "Ints depois de copiar other e apos apagar dois ultimos itens e add 44: ";
    ints.print();

    cout << "\n\n";
    return 0;
}
