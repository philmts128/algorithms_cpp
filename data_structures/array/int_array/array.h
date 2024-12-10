#ifndef VECTOR_H
#define VECTOR_H

namespace ph
{
    class vector
    {
    public:
        vector();
        ~vector();
        void push_back(const int item);
        int at(int index) const;
        int size() const;

    private:
        void resize(const int new_cap);

    private:
        static constexpr int DEF_CAP { 16 };
        int m_size { 0 };
        int m_capacity { DEF_CAP };
        int* m_data { nullptr };
    };
}

#endif
