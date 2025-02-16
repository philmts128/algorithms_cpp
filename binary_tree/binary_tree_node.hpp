#pragma once


namespace pm
{
    //------------------------------------------
    template <typename T>
    struct binary_tree_node
    {
        //------------------------------------------
        T data;
        binary_tree_node* left  { nullptr };
        binary_tree_node* right { nullptr };

        //------------------------------------------
        binary_tree_node(const T& data, binary_tree_node* left = nullptr,
                         binary_tree_node* right = nullptr)
                         : data(data), left(left), right(right) {}
    };
}
