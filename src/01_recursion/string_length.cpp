/**
 * Encontra tamanho de string recursivmente
 * Apenas para fins didáticos pois a performance é ruim
 * Autor: Philippe Matias
 */

#include <iostream>
#include <string>
using namespace std;

/*-----------------------------*/
int str_len(string str)
{
    if (str == "")
        return 0;

    return str_len(str.substr(1)) + 1;
}

/*-----------------------------*/
int main()
{
    cout << "** enter your name: ";
    string name;
    cin >> name;

    cout << "** the name \'"
         << name << "\' has "
         << str_len(name) << " letter(s).";

    cout << "\n\n";
    return 0;
}
