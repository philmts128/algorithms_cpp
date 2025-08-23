#pragma once

#include <stdio.h>

namespace pm
{
    template <typename T>
    struct doubly_linked_list_node final
    {
        T data;
        doubly_linked_list_node<T>* prev { nullptr };
        doubly_linked_list_node<T>* next { nullptr };
        doubly_linked_list_node() {}
        doubly_linked_list_node(const T& data) : data(data) {}
        //~doubly_linked_list_node() { printf("destroyed\n"); }
    };
}
