#pragma once

namespace pm
{
    /*---------------------------*/
    template <typename T>
    struct queue_node
    {
        /*---------------------------*/
        queue_node* next { nullptr };
        T data;

        /*---------------------------*/
        queue_node(const T& data, queue_node<T>* next = nullptr)
        {
            this->data = data;
            this->next = next;
        }

        /*---------------------------*/
        ~queue_node() {
            delete this->next;
        }
    };
}
