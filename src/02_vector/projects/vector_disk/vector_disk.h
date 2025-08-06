#pragma once

#include <cstdint>
#include <string>


/*-----------------------------------------*/
namespace pm {
    #pragma pack(push, 1)
    struct vector_disk_header {
        static constexpr uint64_t Magic_Number { 0xDead };
        size_t size;
        size_t type_size;
        uint64_t magic_number { Magic_Number };
    };
    #pragma pack(pop)
}


/*-----------------------------------------*/
namespace pm
{
    /*-----------------------------------------*/
    class vector_disk final
    {
    public:
        vector_disk(const std::string& path, size_t type_size);
        ~vector_disk();

    public:
        bool init();
        bool add(void* data);
        bool get(size_t index, void* data);
        std::string last_error() const;
        std::size_t get_size() const;

    private:
        bool create_file();
        bool update_header();

    public: //funções de debug
        void print_header();

    private:
        pm::vector_disk_header m_header;
        std::string m_file_path;
        std::string m_last_error;
    };
}
