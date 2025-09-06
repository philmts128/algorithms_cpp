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
void fill_vector(pm::vector<int>& vec, int min, int max)
{
    for (size_t i = 0; i < vec.size(); ++i)
        vec[i] = rand_int(min, max);
}

/*-------------------------------*/
template <typename T>
int linear_search(const pm::vector<T>& vec, const T& item) //O(n) no pior caso e O(1) no melhor.
{
    size_t i = 0;
    for (; i < vec.size(); ++i) {
        if (vec[i] == item) {
            return i;
        }
    }

    return i;
}

/*-------------------------------*/
void test_linear_search()
{
    for (size_t i = 10; i < 100; i += 10)
    {
        const int tries = 100;
        int times = 0;
        int num = rand_int(0, i);
        pm::vector<int> vec(i, false);

        for (int j = 0; j < tries; ++j) {
            fill_vector(vec, 0, i);
            times += linear_search(vec, num);
        }

        times /= tries;
        cout << i << " elements: " << times << '\n';
    }
}


int main()
{
    test_linear_search();

    printf("\n\n");
    return 0;
}
