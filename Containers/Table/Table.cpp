#include <iostream>
#include <Containers/Table/Table.hpp>


Table::Table()
    : Container()
    , tab(NULL)
{ }

Table::~Table()
{
    clear();
}

void Table::reassignTable(int32_t* newTab)
{
    // deallocate current memory and swap with new space address
    if(tab)
    {
        delete tab;
    }

    tab = newTab;
}

void Table::clear()
{
    // deallocate current memory space by setting Table address to NULL
    // set table size to empty
    reassignTable(NULL);
    size = 0;
}

void Table::add(int32_t value, uint32_t index)
{
    // if given index exceeds Table size add element to the end
    // by aligning index value to Table size
    alignOutOfRangeIndexToSize(index);

    // allocate new space larger by 1 element
    size++;
    int32_t* newTab = new int32_t[size];

    // copy current Table values before given index to new memory space
    for(uint32_t it = 0; it < index; ++it)
    {
        newTab[it] = tab[it];
    }

    // assign new value to given index
    newTab[index] = value;

    // rest of the Table to new memory space
    for(uint32_t it = index + 1; it < size; ++it)
    {
        newTab[it] = tab[it - 1];
    }

    // deallocate old memory space and remember address of new space
    reassignTable(newTab);
}

bool Table::remove(uint32_t index)
{
    // if given index exceeds size -> it is invalid
    if(index >= size)
    {
        return false;
    }


    size--;
    if(isEmpty())
    {
        // if last element is removed -> clear table
        reassignTable(NULL);
    }
    else
    {
        // if Table will be not empty after removal -> allocate new space smaller by 1 element
        int32_t* newTab = new int32_t[size];

        // copy current Table values before given index to new memory space
        for(uint32_t it = 0; it < index; ++it)
        {
            newTab[it] = tab[it];
        }

        // rest of the Table to new memory space skipping value from given index
        for(uint32_t it = index + 1; it <= size; ++it)
        {
            newTab[it - 1] = tab[it];
        }

        // deallocate old memory space and remember address of new space
        reassignTable(newTab);
    }

    return true;
}

int32_t Table::get(uint32_t index)
{
    // if given index exceeds Table size -> align it to Table size
    alignOutOfRangeIndexToSize(index);

    // and then decrement it to point to last element in Table
    if(index == size)
    {
        index--;
    }

    return tab[index];
}

bool Table::search(int32_t value)
{
    // linear search - just go through each element and check value
    for(uint32_t it = 0; it < size; ++it)
    {
        if(tab[it] == value)
        {
            return true;
        }
    }

    return false;
}

void Table::display()
{
    if(isEmpty())
    {
        std::cout << "Tablica jest pusta." << std::endl;
    }
    else
    {
        std::cout << "Rozmiar tablicy: " << size << std::endl;

        // just go through each element and print value
        for(uint32_t it = 0; it < size; ++it)
        {
            std::cout << tab[it] << " ";
        }

        std::cout << std::endl;
    }
}
