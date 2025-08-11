#pragma once


namespace pm
{
    template <typename T>
    struct simply_linked_list_node
    {
        T data;
        simply_linked_list_node* next { nullptr };
        simply_linked_list_node() {}
        simply_linked_list_node(const T& data) : data(data) {}
    };
}
