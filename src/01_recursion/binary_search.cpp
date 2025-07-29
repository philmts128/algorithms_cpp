/**
 * Gera intervalo de inteiros ordenados e busca valor recursivamente utilizando binary search
 * Autor: Philippe Matias
 */

#include <iostream>
#include <vector>
using namespace std;


/*-----------------------------*/
int binary_search(const vector<int>& ints, int value, size_t inf, size_t sup)
{
    if (inf >= sup)
        return -1;

    size_t mid = (inf + sup) / 2;
    if (ints[mid] == value)
        return mid;

    if (value > ints[mid])
        return binary_search(ints, value, inf+1, sup);
    else
        return binary_search(ints, value, inf, sup-1);
}

/*-----------------------------*/
void verify(const vector<int> ints, const int value)
{
    if (binary_search(ints, value, 0, ints.size()) == -1) {
        cout << "| " << value << " non ecziste.\n";
    } else {
        cout << "| " << value << " existe!\n";
    }
}

/*-----------------------------*/
auto generate_ordered_ints(vector<int>& ints, int min, int max, int jump = 1) -> vector<int>
{
    if (min > (max+jump))
        return ints;

    ints.push_back(min);

    return generate_ordered_ints(ints, min+jump, max, jump);
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
    cout << "\n| verifique se um valor no intervalo existe[-1 para sair]: ";
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

    cout << "| digite o intervalo que deseja gerar[min, max, salto]: ";
    int min, max, jmp;
    cin >> min >> max >> jmp;

    vector<int> ints;
    generate_ordered_ints(ints, min, max, jmp);

    ask_value(ints);

    cout << "\n| valores gerados: ";
    print(ints);

    cout << "\n\n";
    return 0;
}
