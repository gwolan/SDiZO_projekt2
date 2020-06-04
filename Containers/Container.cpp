#include <Containers/Container.hpp>


Container::Container()
    : size(0)
{ }

bool Container::isEmpty()
{
    return size == 0;
}

uint32_t Container::getSize()
{
    return size;
}

void Container::alignOutOfRangeIndexToSize(uint32_t& index)
{
    if(index > size)
    {
        index = size;
    }
}
