#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#include "vector.h"


int main()
{

    pm::vector<int> f1(999, 555, 777, 666, 222);
    pm::vector<int> f2(5,6,7,8);

    f1 += f2;
    for (auto i : f1)
        cout << i << " ";

    pm::vector<string> colors("\nred", "blue", "green", "black", "white");
    for (const auto& c : colors)
        cout << c << "\n";

    pm::vector<string> langs("\n\nJava", "Python", "C++", "C");
    auto it = langs.begin();
    for (; it != langs.end(); ++it)
        cout << *it << "\n";

    printf("\n\n");
    return 0;
}
