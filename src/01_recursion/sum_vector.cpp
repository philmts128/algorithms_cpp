/**
 * Soma inteiros de um vetor
 * Autor: Philippe Matias
 */

#include <iostream>
#include <vector>
using namespace std;

/*-----------------------------*/
template <class T>
auto sum_vector(const vector<T>& items, size_t n = 0) -> T
{
    if (n == items.size())
        return 0;

    return sum_vector(items, n+1) + items[n];
}

/*-----------------------------*/
int main()
{
    vector<int> ints {1,2,3,4,5,6,7,8,9,10};

    cout << sum_vector(ints);

    cout << "\n\n";
    return 0;
}
