#pragma once

#include <iostream>
#include <cstdint>
#include "binary_tree_node.h"


namespace pm
{
    //------------------------------------------
    template <typename T>
    class binary_tree
    {
    private:
        //------------------------------------------
        pm::binary_tree_node<T>* m_root { nullptr };
        size_t m_size { 0 };

    public:
        //------------------------------------------
        binary_tree() {}

        //------------------------------------------
        binary_tree(const binary_tree& tree)
        {

        }

        //------------------------------------------
        ~binary_tree()
        {

        }

        //------------------------------------------
        bool insert(const T& data)
        {
            auto new_node = new binary_tree_node<T>(data);
            m_size += 1;

            if (this->is_empty()) {
                m_root = new_node;
                return true;
            }

            binary_tree_node<T>* curr = m_root;
            for (;;)
            {
                if (data == curr->data)
                {
                    m_size -= 1;
                    return false;
                }
                else if (data > curr->data)
                {
                    if (curr->right == nullptr) {
                        curr->right = new_node;
                        return true;
                    } else if (curr->data > data) {
                        auto temp = curr->right;
                        curr->right = new_node;
                        new_node->right = temp;
                        return true;
                    } else {
                        curr = curr->right;
                    }
                }
                else
                { // se data for menor
                    if (curr->left == nullptr) {
                        curr->left = new_node;
                        return true;
                    } else if (curr->data < data) {
                        auto temp = curr->left;
                        curr->left = new_node;
                        new_node->left = temp;
                        return true;
                    } else {
                        curr = curr->left;
                    }
                }
            }

            return true;
        }

        //------------------------------------------
        size_t size() const { return m_size; }
        bool is_empty() const { return (m_root == nullptr); }

        //------------------------------------------
        void print()
        {
            post_order(m_root, [](binary_tree_node<T>* n) {
                std::cout <<  n->data << " ";
            });

            std::cout << '\n';
        }

        //------------------------------------------
        template <typename F>
        void pre_order(pm::binary_tree_node<T>* tree, F action)
        {

        }

        //------------------------------------------
        template <typename F>
        void post_order(pm::binary_tree_node<T>* tree, F action)
        {
            if (tree != nullptr) {
                post_order(tree->left, action);
                action(tree);
                post_order(tree->right, action);
            }
        }

        //------------------------------------------
        void copy_data(const binary_tree& tree)
        {

        }

        //------------------------------------------
        void clean_data()
        {

        }
    };
}
