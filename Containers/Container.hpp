#pragma once

#include <cstdint>


class Container
{
    public:
    Container();
    ~Container() = default;

    bool isEmpty();
    uint32_t getSize();
    virtual void clear() = 0;
    virtual void display() = 0;
    virtual int32_t get(uint32_t index) = 0;

    protected:
    void alignOutOfRangeIndexToSize(uint32_t& index);

    uint32_t size;
};
