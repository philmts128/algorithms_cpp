#include <iostream>
#include <string>
using namespace std;

#include "simply_linked_list.h"


int main()
{
    printf("Games:\n");

    pm::simply_linked_list<string> games(
                "Dragon Age: Origins",
                "The ELder Scrolls V: Skyrim",
                "Fallout");
    games.print();

    cout << "\n\n";

    games.append("Legend of Zelda: Ocarina of Time");
    games.append("Star Wars: Knights of the Old Republic");
    games.preppend("Half Life");
    games.preppend("Starcraft");
    games.print(true); //imprime de forma inversa através da recursão

    printf("\n\nDrinks:\n");

    pm::simply_linked_list<string> drinks(
                "strawberry soda", "coca-cola",
                "grape fanta", "pineapple juice", "tea");

    for (const string& d : drinks)
        cout << d << "\n";

    printf("\n\n");
    drinks.remove_back();
    drinks.remove_front();
    drinks.print(true);

    printf("\n\n");
    return 0;
}
