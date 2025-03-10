/**
 * Soma inteiros de um vetor
 * Autor: Philippe Matias
 */

#include <iostream>
using namespace std;

/*-----------------------------*/
int fibonacci_rec(int n)
{
    if (n == 1 || n == 2)
        return 1;

    return fibonacci_rec(n-1) + fibonacci_rec(n-2);
}

/*-----------------------------*/
int fibonacci(int n)
{
    if (n <= 2)
        return 1;

    int a = 1;
    int b = 1;
    int k = 0;

    for (int i = 2; i < n; ++i) {
        k = a + b;
        a = b;
        b = k;
    }

    return k;
}

/*-----------------------------*/
int main()
{
    cout << "Iterativo: ";
    for (int i = 1; i <= 10; ++i)
        cout << fibonacci(i) << " ";

    cout << "\nRecursivo: ";
    for (int i = 1; i <= 10; ++i)
        cout << fibonacci_rec(i) << " ";

    cout << "\n\n";
    return 0;
}
