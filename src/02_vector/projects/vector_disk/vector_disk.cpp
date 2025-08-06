#include <fstream>
#include "vector_disk.h"


namespace pm
{
    /*--------------------------------------------*/
    vector_disk::vector_disk(const std::string& path, size_t type_size)
    {
        m_file_path = path;
        m_header.size = 0;
        m_header.type_size = type_size;
    }


    /*--------------------------------------------*/
    vector_disk::~vector_disk() {
        this->update_header();
    }


    /*--------------------------------------------*/
    bool vector_disk::init()
    {
        std::ifstream in(m_file_path, std::ios::binary);
        if (!in) {
            in.close();
             if (!this->create_file()) {
                 return false;
             }

            return true;
        }

        in.seekg(0);
        in.read(reinterpret_cast<char*>(&m_header), sizeof(pm::vector_disk_header));

        if (! in) {
            m_last_error = "| error on reading header from data file!\n";
            in.close();
            return false;
        }

        if (m_header.magic_number != pm::vector_disk_header::Magic_Number) {
            m_last_error = "| file is not incompatible!\n";
            return false;
        }

        in.close();
        return true;
    }


    /*--------------------------------------------*/
    bool vector_disk::add(void* data)
    {
        auto flags = std::ios::binary  | std::ios::out | std::ios::in;
        std::fstream out(m_file_path, flags);
        if (!out) {
            m_last_error = "| unable to open file for adding new data!\n";
            return false;
        }

        out.seekp(sizeof(pm::vector_disk_header) + m_header.size * m_header.type_size);
        out.write(reinterpret_cast<char*>(data), m_header.type_size);

        if (!out) {
            m_last_error = "| failed to add data in the file!\n";
            return false;
        }

        m_header.size += 1;
        out.close();
        this->update_header();
        return true;
    }


    /*--------------------------------------------*/
    bool vector_disk::get(size_t index, void* data)
    {
        std::ifstream in(m_file_path, std::ios::binary);
        if (!in) {
            m_last_error = "| unable to open file to retrieve data!\n";
            return false;
        }

        auto pos = sizeof(pm::vector_disk_header) + index * m_header.type_size;
        in.seekg(pos);

        in.read(reinterpret_cast<char*>(data), m_header.type_size);
        if (!in) {
            m_last_error = "| unable to read data from file!\n";
            return false;
        }

        in.close();
        return true;
    }


    /*--------------------------------------------*/
    bool vector_disk::create_file()
    {
        auto flags = std::ios::binary;

        std::ofstream out(m_file_path, flags);
        if (! out) {
            m_last_error = "| unable to create data file!\n";
            return false;
        }

        out.write(reinterpret_cast<char*>(&m_header), sizeof(pm::vector_disk_header));
        out.flush();

        if (! out) {
            m_last_error = " | unable to record header on file creation!\n";
            return false;
        }

        out.close();
        return true;
    }


    /*--------------------------------------------*/
    bool vector_disk::update_header()
    {
        auto flags = std::ios::binary | std::ios::in | std::ios::out;

        std::fstream out(m_file_path, flags);
        out.seekp(0);
        out.write(reinterpret_cast<char*>(&m_header), sizeof(pm::vector_disk_header));

        if (! out) {
            m_last_error = " | unable to update header!\n";
            return false;
        }

        out.close();
        return true;
    }


    /*--------------------------------------------*/
    std::string vector_disk::last_error() const {
        return m_last_error;
    }


    /*--------------------------------------------*/
    std::size_t vector_disk::get_size() const {
        return m_header.size;
    }
}
