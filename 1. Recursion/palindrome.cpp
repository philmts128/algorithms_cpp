/**
 * Verifica recursivamente se texto em ASCII é palindromo
 * Autor: Philippe Matias
 */

#include <iostream>
#include <string>
using namespace std;

/*-----------------------------*/
bool palindrome(const string& str, int n = 0)
{
    static auto j = [&str](int inc) { return (int)str.size() - (inc+1); };

    if (str[n] != str[j(n)])
        return false;

    if (n >= j(n))
        return true;

    return palindrome(str, n+1);
}


/*-----------------------------*/
int main()
{
    string txt;
    while (getline(cin, txt)) {
        if (palindrome(txt))
            cout << txt << " is palindrome!\n";
        else
            cout << txt << " is not palindrome!\n";
    }

    cout << "\n\n";
    return 0;
}
