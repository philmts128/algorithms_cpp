#pragma once


namespace pm {
    template <typename T>
    class simply_linked_list;

    template <typename T>
    struct simply_linked_list_node;
}


namespace pm
{
    template <typename T>
    class simply_linked_list_iterator final
    {
    private:
        simply_linked_list_node<T>* m_node;

    public:
        simply_linked_list_iterator(simply_linked_list_node<T>* node = nullptr) {
            m_node = node;
        }


        bool operator == (simply_linked_list_iterator other) const {
            return (m_node == other.m_node);
        }


        bool operator != (simply_linked_list_iterator other) const {
            return !(m_node == other.m_node);
        }


        auto operator * () -> T {
            return m_node->data;
        }


        auto operator ++ () -> simply_linked_list_iterator {
            m_node = m_node->next;
            return *this;
        }
    };
}
