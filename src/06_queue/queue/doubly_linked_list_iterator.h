#pragma once


namespace pm {
    template <typename T>
    class doubly_linked_list;

    template <typename T>
    struct doubly_linked_list_node;
}


namespace pm
{
    template <typename T>
    class doubly_linked_list_iterator final
    {
    private:
        doubly_linked_list_node<T>* m_node;

    public:
        doubly_linked_list_iterator(doubly_linked_list_node<T>* node = nullptr) {
            m_node = node;
        }


        bool operator == (doubly_linked_list_iterator other) const {
            return (m_node == other.m_node);
        }


        bool operator != (doubly_linked_list_iterator other) const {
            return !(m_node == other.m_node);
        }


        auto operator * () -> T {
            return m_node->data;
        }


        auto operator ++ () -> doubly_linked_list_iterator {
            m_node = m_node->next;
            return *this;
        }


        auto operator -- () -> doubly_linked_list_iterator {
            m_node = m_node->prev;
            return *this;
        }
    };
}
