/**
* Implementação de nó de árvore binária
* Autor: Philippe Matias
*/

#pragma once

#include <iostream>

namespace pm
{
    /*--------------------------------------------*/
    template <typename T>
    struct binary_tree_node
    {
        /*--------------------------------------------*/
        binary_tree_node* left  { nullptr };
        binary_tree_node* right { nullptr };
        T data;

        /*--------------------------------------------*/
        binary_tree_node() {}

        /*--------------------------------------------*/
        ~binary_tree_node()
        {
            std::cout << "node destroyed!\n";
        }

        /*--------------------------------------------*/
        binary_tree_node(const T& data) : data(data)
        {
            std::cout << "node created!\n";
        }
    };
}
