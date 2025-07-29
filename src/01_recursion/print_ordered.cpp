/**
 * Imprime um intervalode inteiros em ordens crescente e decrescente.
 * Autor: Philippe Matias
 */

#include <iostream>
using namespace std;

/*-----------------------------*/
void print_descending(int min, int max)
{
    if (max < min) {
        cout << "\n";
        return;
    }

    cout << max << " ";
    print_descending(min, max-1);
}

/*-----------------------------*/
void print_descending(int limit) {
    print_descending(0, limit);
}

/*-----------------------------*/
void print_ascending(int min, int max)
{
    if (min > max) {
        cout << "\n";
        return;
    }

    cout << min << ' ';
    print_ascending(min+1, max);
}

/*-----------------------------*/
void print_ascending(int limit) {
    print_ascending(0, limit);
}

/*-----------------------------*/
int main()
{
    print_descending(10, 20);
    print_ascending(15, 25);
    print_descending(9);
    print_ascending(9);
    return 0;
}
