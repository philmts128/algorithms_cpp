#include <iostream>
using namespace std;

#include "vector_disk.h"

struct pessoa {
    char nome[100];
    int idade;
};

int main()
{
    pessoa p;

    printf("| digite seu nome: ");
    scanf("%[^\n]", p.nome);

    printf("| digite sua idade: ");
    scanf(" %d", &p.idade);

    pm::vector_disk pessoas("pes.txt", sizeof(pessoa));
    pessoas.init();

    pessoas.add(&p);

    for (size_t i = 0; i < pessoas.get_size(); ++i) {
        pessoa tp;
        pessoas.get(i, &tp);

        printf("\n\n------------------------\n");
        printf("Nome: %s\n", tp.nome);
        printf("Idade: %d\n", tp.idade);
    }

    printf("\n\n");
    return 0;
}
