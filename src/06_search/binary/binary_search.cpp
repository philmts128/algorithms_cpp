/*
 * Implementção e teste de busca linear em vetor
 * Autor: Philippe Matias
*/

#include <iostream>
using namespace std;

#include "vector.h"


/*-------------------------------*/
auto generate_ord_vector(int min, int max) -> pm::vector<int>
{
    pm::vector<int> n;
    for (int i = 0; i < max; i++)
        n.append(min + i);
    return n;
}

/*-------------------------------*/
template <typename T>
int binary_search(const pm::vector<T>& vec, const T& item) //O(n) no pior caso e O(1) no melhor.
{
    size_t inf = 0;
    size_t sup = vec.size() - 1;

    while (inf <= sup)
    {
        size_t pos = (sup + inf)/2;

        if (vec[pos] == item) {
            return pos;
        } else if (item > vec[pos]) {
            inf = pos;
        } else if (item < vec[pos]) {
            sup = pos;
        }
    }

    return -1;
}

/*-------------------------------*/
void test_binary_search()
{
    auto vec = generate_ord_vector(1, 100);

    cout << "| enter an integer[-1 para sair]: ";
    int n;
    cin >> n;

    if (n == -1)
        return;

    int pos;
    if ((pos = binary_search(vec, n)) == -1) {
        cout << ">> " << n << " nao existe!\n\n";
    } else {
        cout << ">> " << n << " esta na posicao " << pos << "\n\n";
    }

    test_binary_search();
}


int main()
{
    test_binary_search();

    printf("\n\n");
    return 0;
}
