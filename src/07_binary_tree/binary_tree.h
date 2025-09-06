/**
* Implementação de árvore binária sem repetição de busca em  C++
* Autor: Philippe Matias
*/

#pragma once

#include <iostream>
#include "binary_tree_node.h"
#include "object_pool.h"


namespace pm
{
    /*--------------------------------------------*/
    template <typename T>
    class binary_tree
    {
    private:
        /*--------------------------------------------*/
        pm::binary_tree_node<T>* m_root { nullptr };
        pm::object_pool<binary_tree_node<T>> m_pool { 128 };
        size_t m_size { 0 };

    public:
        /*--------------------------------------------*/
        binary_tree() {}

        /*--------------------------------------------*/
        binary_tree(const binary_tree& tree) { this->copy_data(tree); }

        /*--------------------------------------------*/
        explicit binary_tree(binary_tree&&)
        {
            //todo
        }

        /*--------------------------------------------*/
        ~binary_tree() { this->clear(); }

        /*--------------------------------------------*/
        void insert(const T& data)
        {
            m_size += 1;
            auto new_node = m_pool.allocate(data);

            if (m_root == nullptr) {
                m_root = new_node;
                return;
            }

            binary_tree_node<T>* next = m_root;
            while (next != nullptr)
            {
                if (data == next->data) //se já existir item, não faz nada
                {
                    return;
                }
                else if (data > next->data) //se for maior, vai para nó da direita
                {
                    if (next->right == nullptr) {
                        next->right = new_node;
                        return;
                    } else {
                        next = next->right;
                    }
                }
                else //se for menor, vai para nó da esquerda
                {
                    if (next->left == nullptr) {
                        next->left = new_node;
                        return;
                    } else {
                        next = next->left;
                    }
                }
            }
        }

        /*--------------------------------------------*/
        auto min() -> T
        {
            auto node = m_root;
            while (node->left != nullptr) {
                node = node->left;
            }

            return node->data;
        }

        /*--------------------------------------------*/
        auto max() -> T
        {
            auto node = m_root;
            while (node->right != nullptr) {
                node = node->right;
            }

            return node->data;
        }

        /*--------------------------------------------*/
        void remove(const T&)
        { 
            //TODO
        }

        /*--------------------------------------------*/
        void clear()
        {
            if (m_root) {
                this->in_order([&](binary_tree_node<T>* n) {
                    m_pool.deallocate(n);
                }, m_root);

                m_root = nullptr;
                m_size = 0;
            }
        }

        /*--------------------------------------------*/
        void print()
        {
            in_order([](binary_tree_node<T>* n){
                std::cout << n->data << "\n";
            }, m_root);
        }
    private:
        /*--------------------------------------------*/
        template <typename F>
        void in_order(F function, pm::binary_tree_node<T>* node = nullptr)
        {
            if (node != nullptr) {
                in_order(function, node->left);
                function(node);
                in_order(function, node->right);
            }
        }

        /*--------------------------------------------*/
        template <typename F>
        void pre_order(F function, pm::binary_tree_node<T>* node = nullptr)
        {
            if (node != nullptr) {
                function(node);
                pre_order(function, node->left);
                pre_order(function, node->right);               
            }
        }

        /*--------------------------------------------*/
        template <typename F>
        void post_order(F function, pm::binary_tree_node<T>* node = nullptr)
        {
            if (node != nullptr) {
                post_order(function, node->left);
                post_order(function, node->right);
                function(node);
            }
        }

        /*--------------------------------------------*/
        void copy_data(const binary_tree<T>& tree)
        {
            this->clear();
            this->in_order([&](binary_tree_node<T>* n) {
                this->insert(n->data);
            }, tree.m_root);
        }
    };
}
