#ifndef STACK_NODE_H
#define STACK_NODE_H

namespace pm
{
    /*----------------------*/
    template <typename T>
    struct stack_node
    {
        /*----------------------*/
        T data;
        stack_node* next;

        /*----------------------*/
        stack_node(const T& data, stack_node* next = nullptr) {
            this->data = data;
            this->next = nullptr;
        }

        /*----------------------*/
        ~stack_node() {
            delete next;
        }
    };
}

#endif // STACK_NODE_H
