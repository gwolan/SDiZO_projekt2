#include <iostream>
#include <Containers/List/List.hpp>


List::List()
    : Container()
    , head(NULL)
    , tail(NULL)
    , invalidIndex(-1)
{ }

List::~List()
{
    clear();
}

void List::clear()
{
    // if pointers to HEAD and TAIL point to any List node
    if(head && tail)
    {
        // go through whole List node by node
        for(uint32_t it = 0; it < size; ++it)
        {
            if(head != tail)
            {
                // move HEAD pointer forward and delete previous node
                head = head->next;

                delete head->prev;
                head->prev = NULL;
            }
            else
            {
                // if HEAD point to the same node as TAIL
                // it means that there is only 1 node in the List
                // so just delete it
                delete head;
            }
        }

        // NULL HEAD and TAIL pointers and set size to empty - defaults
        head = NULL;
        tail = NULL;
        size = 0;
    }
}

void List::add(int32_t value, uint32_t index)
{
    // if given index exceeds List size add element to the end
    // by aligning index value to List size
    alignOutOfRangeIndexToSize(index);

    if(head && tail)
    {
        // List is not empty, just add new node

        // initialize pointer that is going to jump through List nodes
        ListNode* tmp = head;

        // set pointer to position of the node pointed by index
        for(uint32_t it = 0; it < index; ++it)
        {
            tmp = tmp->next;
        }

        // create new node and reassign connections between nodes to add new one
        ListNode* newNode = new ListNode();
        newNode->value = value;
        newNode->prev = tmp->prev;
        newNode->next = tmp;

        tmp->prev->next = newNode;
        tmp->prev = newNode;

        // handle corner cases
        if(index == size)
        {
            // add new node on the end
            tail = tail->next;
        }
        else if(tmp == head)
        {
            // add new node at the beginning
            head = head->prev;
        }
    }
    else
    {
        // List is empty, create new node and initialize HEAD/TAIL pointers
        ListNode* newNode = new ListNode();
        newNode->value = value;
        newNode->prev = newNode;
        newNode->next = newNode;

        head = newNode;
        tail = newNode;
    }

    size++;
}

bool List::remove(int32_t value)
{
    if(head && tail)
    {
        // remove only if List is not empty

        // initialize pointer that is going to jump through List nodes
        ListNode* tmp = head;

        // go through all nodes
        for(uint32_t it = 0; it < size; ++it)
        {
            if(tmp->value == value)
            {
                // if given node value matches node value on the list - remove this node
                removeNode(tmp);

                size--;
                if(isEmpty())
                {
                    // additionaly set HEAD/TAIL pointers to NULL if list is empty after removal
                    head = NULL;
                    tail = NULL;
                }

                return true;
            }
            else
            {
                // otherwise go to the next node and keep searching
                tmp = tmp->next;
            }
        }
    }

    return false;
}

void List::removeNode(ListNode* removedNode)
{
    // reassign connections between nodes to remove given node
    removedNode->prev->next = removedNode->next;
    removedNode->next->prev = removedNode->prev;

    // handle corner cases
    if(removedNode == tail)
    {
        // removal of the last node
        tail = tail->prev;
    }
    else if(removedNode == head)
    {
        // removal of the first node
        head = head->next;
    }

    delete removedNode;
}

bool List::search(int32_t value)
{
    if(head && tail)
    {
        // search only if List is not empty

        // initialize pointer that is going to jump through List nodes
        ListNode* tmp = head;

        // go through all nodes
        for(uint32_t it = 0; it < size; ++it)
        {
            if(tmp->value == value)
            {
                // return true if value matches value in the node
                return true;
            }

            // keep searching
            tmp = tmp->next;
        }
    }

    return false;
}

int32_t List::get(uint32_t index)
{
    if(head && tail)
    {
        alignOutOfRangeIndexToSize(index);
        if(index == size)
        {
            index--;
        }

        ListNode* tmp = head;
        for(uint32_t it = 0; it < index; ++it)
        {
            tmp = tmp->next;
        }

        return tmp->value;
    }

    return invalidIndex;
}

void List::display()
{
    if(isEmpty())
    {
        std::cout << "Lista jest pusta." << std::endl;
    }
    else
    {
        std::cout << "Rozmiar listy: " << size << std::endl;

        ListNode* tmp = head;
        std::cout << std::endl << "Lista w przod: " << std::endl;
        for(uint32_t it = 0; it < size; ++it)
        {
            std::cout << tmp->value << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;

        tmp = tail;
        std::cout << std::endl << "Lista w tyl: " << std::endl;
        for(uint32_t it = 0; it < size; ++it)
        {
            std::cout << tmp->value << " ";
            tmp = tmp->prev;
        }
        std::cout << std::endl << std::endl;
    }
}
