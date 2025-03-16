/**
 * Converte inteiro em decimal para base binária.
 * Autor: Philippe Matias
 */

#include <iostream>
#include <string>
using namespace std;

/*-----------------------------*/
char convert_char(int num)
{
    if (num >= 0 && num <= 9)
        return num + 48;
    if (num >= 10 && num <= 15)
        return num + 55;
    return -1;
}

/*-----------------------------*/
template <int Base>
void convert(string& bin, int dec)
{
    if (dec > 0) {
        convert<Base>(bin, dec/Base);
        bin.push_back(convert_char(dec % Base));
    }
}


/*-----------------------------*/
int main()
{
    int num;
    while (cin>>num && num >= 0) {
        string buffer;
        convert<16>(buffer, num);
        cout << buffer << "\n\n";
    }

    cout << "\n\n";
    return 0;
}
