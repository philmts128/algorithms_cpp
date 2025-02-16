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
            if (m_root != nullptr) {
                this->clean_data();
            }
        }

        //------------------------------------------
        bool insert(const T& data)
        {
            if (this->is_empty()) {
                m_root = new binary_tree_node<T>(data);
                return true;
            }

            binary_tree_node<T>* curr = m_root;
            binary_tree_node<T>* prev = nullptr;

            while (curr != nullptr)
            {
                prev = curr;

                if (curr->data == data) {
                    return false;
                } else if (data > curr->data) {
                    curr = curr->right;
                } else {
                    curr = curr->left;
                }
            }

            auto new_node = new binary_tree_node<T>(data);
            if (data > prev->data)
                prev->right = new_node;
            else
                prev->left = new_node;

            return true;
        }

        //------------------------------------------
        size_t size() const { return m_size; }
        bool is_empty() const { return (m_root == nullptr); }

        //------------------------------------------
        void print()
        {
            in_order(m_root, [](binary_tree_node<T>* n) {
                std::cout <<  n->data << " ";
            });

            std::cout << '\n';
        }

        //------------------------------------------
        template <typename F>
        void pre_order(pm::binary_tree_node<T>* tree, F action)
        {
            if (tree != nullptr) {
                action(tree);
                pre_order(tree->left, action);
                pre_order(tree->right, action);
            }
        }

        //------------------------------------------
        template <typename F>
        void post_order(pm::binary_tree_node<T>* tree, F action)
        {
            if (tree != nullptr) {
                post_order(tree->left, action);
                post_order(tree->right, action);
                action(tree);
            }
        }

        //------------------------------------------
        template <typename F>
        void in_order(pm::binary_tree_node<T>* tree, F action)
        {
            if (tree != nullptr) {
                in_order(tree->left, action);
                action(tree);
                in_order(tree->right, action);
            }
        }

        //------------------------------------------
        void copy_data(const binary_tree& tree)
        {

        }

        //------------------------------------------
        void clean_data()
        {
            this->post_order(m_root, [](binary_tree_node<T>* n) {
                delete n;
            });
        }
    };
}
