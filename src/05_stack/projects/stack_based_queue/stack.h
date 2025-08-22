#pragma once

#include "vector.h"


/*-----------------------------*/
namespace pm
{
    /*-----------------------------*/
    template <typename T>
    class stack final
    {
    private:
        /*-----------------------------*/
        pm::vector<T> m_data;

    public:
        /*-----------------------------*/
        stack() {
        }

        /*-----------------------------*/
        void push(const T& data) {
            m_data.append(data);
        }

        /*-----------------------------*/
        void pop() {
            m_data.remove_back();
        }

        /*-----------------------------*/
        auto top() -> T {
            return m_data.at(m_data.size()-1);
        }

        /*-----------------------------*/
        auto size() -> size_t {
            return m_data.size();
        }

        /*-----------------------------*/
        auto is_empty() -> bool {
            return m_data.is_empty();
        }
    };
}
