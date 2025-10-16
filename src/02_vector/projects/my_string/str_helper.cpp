#include "str_helper.h"


namespace pm
{
    /*--------------------------------*/
    size_t str_len(const char* str)
    {
        size_t s = 0;
        for (; str[s] != 0; ++s);
        return s; 
    }

    //INEFICIENTE. DEPOIS FAÇO UMA VERSÃO MELHORADA
    void str_copy(const char* src, char* dest, size_t size)
    {
        auto limit = str_len(dest) <= size ? str_len(dest) : size;
        for (size_t i = 0; i < limit; ++i) {

        }
    }
}