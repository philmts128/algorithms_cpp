/*
 * Implementção e teste de busca linear em vetor
 * Autor: Philippe Matias
*/

#include <iostream>
#include <map>
#include <random>
using namespace std;

#include "vector.h"

/*-------------------------------*/
int rand_int(int min, int max)
{
    random_device rnd;
    mt19937 rng(rnd());
    uniform_int_distribution<int> uni(min, max);
    return uni(rng);
}

/*-------------------------------*/
auto generate_vector(int num, int min, int max) -> pm::vector<int>
{
    pm::vector<int> n;
    for (int i = 0; i < num; ++i)
        n.append(rand_int(min, max));
    return n;
}

/*-------------------------------*/
template <typename T>
int linear_search(const pm::vector<T>& vec, const T& item) //O(n) no pior caso e O(1) no melhor.
{
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == item) {
            return i;
        }
    }

    return -1;
}

/*-------------------------------*/
void test_linear_search()
{
    auto vec = generate_vector(20, 1, 100);

    cout << "| enter an integer[-1 para sair]: ";
    int n;
    cin >> n;

    if (n == -1)
        return;

    int pos;
    if ((pos = linear_search(vec, n)) == -1) {
        cout << ">> " << n << " nao existe!\n\n";
    } else {
        cout << ">> " << n << " esta na posicao " << pos << "\n\n";
    }

    test_linear_search();
}


int main()
{
    test_linear_search();

    printf("\n\n");
    return 0;
}
