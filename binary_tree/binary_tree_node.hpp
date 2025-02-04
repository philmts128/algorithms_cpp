#pragma once


namespace mx
{
    /*------------------------------------------*/
    template <typename T>
    struct binary_tree_node
    {
        /*------------------------------------------*/
        binary_tree_node* left  { nullptr };
        binary_tree_node* right { nullptr };
        T data;
        
        /*------------------------------------------*/
        binary_tree_node(const T& data,
            binay_tree_node* left = nullptr, binary_tree_node* right = nullptr)
            : left(this->left), right(this->right) {}
    };
}
