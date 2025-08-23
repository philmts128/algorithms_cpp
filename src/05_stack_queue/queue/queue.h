#pragma once

#include "fast_linked_list.h"


namespace pm
{
    template <typename T>
    class queue final
    {
    private:
        pm::fast_linked_list<T> m_data;

    public:
        queue() {}

        void enqueue(const T& item) {
            m_data.preppend(item);
        }

        void dequeue() {
            m_data.remove_back();
        }

        auto front() -> T {
            return m_data.last();
        }

        auto size() -> size_t {
            return m_data.size();
        }

        auto is_empty() -> bool {
            return m_data.is_empty();
        }
    };
}
