#pragma once

#include <Containers/Container.hpp>


// Table implementation
// Written in C++98 without STL use


class Table : public Container
{
    public:
    Table();
    ~Table();

    void clear();
    void display();
    void add(int32_t value, uint32_t index);
    bool remove(uint32_t index);
    int32_t get(uint32_t index);
    bool search(int32_t value);


    private:
    void reassignTable(int32_t* newTab);

    int32_t* tab;
};
