#include "vector.h"


namespace ph
{
    vector::vector()
    {
        m_data = new int[m_capacity];
    }

    vector::~vector()
    {
        if (m_data != nullptr) {
            delete[] m_data;
            m_data = nullptr;
        }
    }

    void vector::push_back(const int item)
    {
        if (m_size >= m_capacity) {
            this->resize(m_capacity);
        }

        m_data[m_size] = item;
        m_size +=1;
    }

    int vector::at(int index) const
    {
        return m_data[index];
    }

    int vector::size() const
    {
        return m_size;
    }

    void vector::resize(const int new_cap)
    {
        if (new_cap == m_capacity) return;

        int* new_arr = new int[new_cap];
        int size = (new_cap < m_size) ? new_cap : m_size;
        for (int i = 0; i < size; ++i)
            new_arr[i] = m_data[i];

        delete[] m_data;
        m_data = new_arr;
        m_capacity = new_cap;
    }
}
