#pragma once
#include <cstdint>


// List node definition
// each List node holds value, pointer to previous and next node


struct ListNode
{
    ListNode* prev;
    ListNode* next;
    int32_t value;
};
