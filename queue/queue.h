#pragma once

#include "queue_node.h"


namespace pm
{
    /*--------------------------------------*/
    template <typename T>
    class queue
    {
    private:
        /*--------------------------------------*/
        pm::queue_node* m_head { nullptr };
        pm::queue_node* m_tail { nullptr};
        int m_size { 0 };

    public:
        /*--------------------------------------*/
        queue()
        {

        }

        /*--------------------------------------*/
        ~queue()
        {

        }

        /*--------------------------------------*/
        void enqueue(const T& item)
        {

        }

        /*--------------------------------------*/
        auto dequeue() -> const T&
        {

        }

        /*--------------------------------------*/
        int size() const { return m_size; }
        bool empty() const  { (m_size == 0); }
    };
}
