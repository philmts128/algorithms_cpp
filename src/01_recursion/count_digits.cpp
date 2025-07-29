/**
 * Soma todos o dígitos dentro de uma string
 * Autor: Philippe Matias
 */

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

/*-----------------------------*/
int sum_digits(const string& str, size_t k = 0)
{
    if (k == str.size())
        return 0;

    int x = isdigit(str[k]) ? (str[k] - 48) : 0;
    return sum_digits(str, k + 1) + x;
}

/*-----------------------------*/
void print(const string& str)
{
    cout << "| " << str
         << " - " << sum_digits(str)
         << "\n";
}

/*-----------------------------*/
int main()
{
    string t1 = "1ewqeq3";
    string t2 = "3ac4";
    string t3 = "555dsdad222";
    string t4 = "vcvxvxvxv";

    print(t1);
    print(t2);
    print(t3);
    print(t4);

    cout << "\n\n";
    return 0;
}
