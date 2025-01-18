/**
 * Implementação de nó de lista simplesmente encadeda em C++
 * Autor: Philippe Matias
*/

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

namespace pm
{
    template <typename T>
    struct linked_list_node
    {
        //atributos
        T data;
        linked_list_node* next { nullptr }; //next sempre inicia com nullptr

        //construtor padrão
        linked_list_node() {}

        //construtor para inicilizar atributos
        linked_list_node(const T& data, linked_list_node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };
}

#endif // LINKED_LIST_NODE_H
