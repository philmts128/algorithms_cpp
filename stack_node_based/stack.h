#ifndef STACK_H
#define STACK_H

#include "stack_node.h"


namespace pm
{
    /*----------------------*/
    template <typename T>
    class stack
    {
    private:
        stack_node<T>* m_top { nullptr };

    public:
        stack() {}
    };
}


#endif // STACK_H_INCLUDED
