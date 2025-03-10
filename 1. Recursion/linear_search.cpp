/**
 * Gera array de inteiros positivos aleatórios e verifica se valor existe
 * Autor: Philippe Matias
 */

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;


/*-----------------------------*/
int linear_search(const vector<int> ints, size_t length, const int value)
{
    if (length == (size_t)(-1))
        return -1;

    if (ints[length] == value)
        return length;

    return linear_search(ints, length-1, value);
}

/*-----------------------------*/
void verify(const vector<int> ints, const int value)
{
    if (linear_search(ints, ints.size(), value) == -1) {
        cout << "| " << value << " non ecziste.\n";
    } else {
        cout << "| " << value << " existe!\n";
    }
}

/*-----------------------------*/
auto generate_vector(int amount) -> vector<int>
{
    vector<int> ints;
    for (int i = 0; i <= amount; ++i)
        ints.push_back((rand() % 100) + 1);
    return ints;
}

/*-----------------------------*/
void print(const vector<int>& ints, size_t n = 0)
{
    if (n == ints.size()-1)
        return;
    cout << ints[n] << " ";
    print(ints, n+1);
}

/*-----------------------------*/
void ask_value(const vector<int>& ints)
{
    cout << "| adivinha se um valor de 0 a 100 existe[-1 para sair]: ";
    int n;
    cin >> n;

    if (n == -1) {
        return;
    } else {
        verify(ints, n);
        ask_value(ints);
    }

}

/*-----------------------------*/
int main()
{
    srand(time(NULL));

    cout << "| entre com a quantidade de inteiros que deseja gerar: ";
    int amount;
    cin >> amount;

    auto ints = generate_vector(amount);
    ask_value(ints);

    cout << "\n| valores gerados: ";
    print(ints);

    cout << "\n\n";
    return 0;
}
