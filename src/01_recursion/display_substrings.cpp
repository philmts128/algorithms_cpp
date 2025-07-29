/**
 * Exibe recursivamrnte as substrings de uma string
 * Autor: Philippe Matias
 */

#include <iostream>
#include <string>
using namespace std;

/*-----------------------------*/
void substring_asc(string str)
{
    if (str == "")
        return;

    cout << str << '\n';
    substring_asc(str.substr(1));
}

/*-----------------------------*/
void substring_desc(string str)
{
    if (str == "")
        return;

    substring_desc(str.substr(1));
    cout << str << '\n';
}

/*-----------------------------*/
int main()
{
    string fruit = "apple";

    cout << "| ascending:\n";
    substring_asc(fruit);

    cout << "\n| descending:\n";
    substring_desc(fruit);

    cout << "\n\n";
    return 0;
}
