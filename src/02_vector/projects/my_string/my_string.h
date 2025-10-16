#pragma once

#include <cstdint>
#include <cstdlib>


namespace pm
{
    class my_string final
    {
    public:
        my_string();
        my_string(const char* str);
        ~my_string();

    public:
        operator char* () { return m_data; }

    private:
        static constexpr size_t Min_Cap { 64 };
        char* m_data { nullptr };
        size_t m_length { 0 };
        size_t m_capacity { Min_Cap };
    };
}