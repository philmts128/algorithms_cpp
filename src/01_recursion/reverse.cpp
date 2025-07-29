/**
 * Inverte a ordem de uma lista/coleção recursivamente
 * Autor: Philippe Matias
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*-----------------------------*/
template <typename T>
void print(const T& list)
{
    for (const auto& i: list)
        cout << i << " ";
    cout << '\n';
}

/*-----------------------------*/
template <typename T>
void swap_items(T& a, T& b)
{
    auto tmp = a;
    a = b;
    b = tmp;
}

/*-----------------------------*/
template <typename T>
int reverse(T& items, size_t n = 0)
{
    if (n == items.size()/2)
        return 0;

    size_t k = reverse(items, n+1);
    size_t j = items.size()-(k+1);
    swap_items(items[k], items[j]);
    return k+1;
}




/*-----------------------------*/
int main()
{
    vector<int> nums {0,1,2,3,4,5,6,7,8,9};
    reverse(nums);
    print(nums);

    string name = "bulldog";
    reverse(name);
    cout << name;

    cout << "\n\n";
    return 0;
}
