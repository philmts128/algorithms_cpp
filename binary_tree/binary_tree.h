#pragma once

#include <iostream>
#include "binary_tree_node.h"


namespace pm
{
  template <typename T>
  class binary_tree
  {
  private:
    binary_tree_node<T>* m_root { nullptr };
    int m_size { 0 };

  public:
      binary_tree() {}

      void insert(const T& data)
      {
          if (this->empty()) {
            m_root = new binary_tree_node<T>(data);
            m_size = 1;
            return ;
          }

          binary_tree_node<T>* cur = m_root;
          while (cur != nullptr)
          {
              if (cur->data == data) {
                return;
              } else if (data < cur->data) {
                  if (cur->left == nullptr) {
                    cur->left = new binary_tree_node<T>(data);
                    m_size += 1;
                    return;
                  } else {
                    cur = cur->left;
                    continue;
                  }
              } else if (data > cur->data) {
                  if (cur->right == nullptr) {
                    cur->right = new binary_tree_node<T>(data);
                    m_size += 1;
                    return;
                  } else {
                    cur = cur->right;
                    continue;
                  }
              }
          }
      }

      template <typename F>
      void post_traversal(binary_tree_node<T>* root, F action)
      {
          if (root != nullptr) {
            post_traversal(root->left, action);
            action(root->data);
            post_traversal(root->right, action);
          }
      }

      void print()
      {
          post_traversal(m_root, [](const T& d) {
            std::cout << d << " ";
            });
      }

      int size() const { return m_size; }
      bool empty() const { return (m_root == nullptr); }
  };
}
