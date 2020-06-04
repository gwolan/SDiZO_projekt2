#include <iostream>
#include <string>
#include <Containers/Heap/Heap.hpp>


Heap::Heap()
    : Container()
    , tab(NULL)
    , invalidIndex(-1)
{ }

Heap::~Heap()
{
    clear();
}

void Heap::clear()
{
    // deallocate current memory space
    if(tab)
    {
        delete tab;
        tab = NULL;
    }

    // set Heap size and capacity to empty
    size = 0;
    capacity = 0;
}

bool Heap::allocateCapacity(uint32_t newCapacity)
{
    // allocate only if requested capacity is larger
    if(newCapacity <= capacity)
    {
        return false;
    }

    if(tab)
    {
        // if Heap exists just allocate larger memory space
        // and copy values to new location
        int32_t* newTab = new int32_t[newCapacity];

        for(uint32_t it = 0; it < size; ++it)
        {
            newTab[it] = tab[it];
        }

        // delete old content and remember new address
        delete tab;
        tab = newTab;
    }
    else
    {
        // if Heap is empty just allocate new space
        tab = new int32_t[newCapacity];
    }

    // remember new capacity
    capacity = newCapacity;
    return true;
}

void Heap::extendCapacityIfNeeded()
{
    if(isEmpty())
    {
        // if Heap is empty allocate basic memory space
        allocateCapacity(2);
    }
    else if(size + 1 > capacity)
    {
        // always allocate additional memory by doubling current capacity
        allocateCapacity(2 * capacity);
    }
}

uint32_t Heap::parentNodeId(uint32_t currentNode)
{
    // calculate parent node ID
    return (currentNode - 1) / 2;
}

uint32_t Heap::leftSiblingNodeId(uint32_t currentNode)
{
    // calculate left sibling node ID
    return currentNode * 2 + 1;
}

uint32_t Heap::rightSiblingNodeId(uint32_t currentNode)
{
    // calculate right sibling node ID
    return currentNode * 2 + 2;
}

int32_t Heap::nodeValue(uint32_t nodeId)
{
    return tab[nodeId];
}

bool Heap::leftSiblingExists(uint32_t nodeId)
{
    // left sibling exists if its node ID fits to Heap size
    return leftSiblingNodeId(nodeId) < size;
}

bool Heap::rightSiblingExists(uint32_t nodeId)
{
    // right sibling exists if its node ID fits to Heap size
    return rightSiblingNodeId(nodeId) < size;
}

void Heap::swapNodeValues(uint32_t nodeIdSource, uint32_t nodeIdTarget)
{
    int32_t valuePlaceHolder = tab[nodeIdTarget];
    tab[nodeIdTarget] = nodeValue(nodeIdSource);
    tab[nodeIdSource] = valuePlaceHolder;
}

void Heap::fixHeapUp(uint32_t nodeId)
{
    uint32_t parentNode = parentNodeId(nodeId);

    // keep fixing if given node is not a root and its parent node value is lower
    while(nodeId > 0 && nodeValue(parentNode) < nodeValue(nodeId))
    {
        // swap node value with his parent
        swapNodeValues(parentNode, nodeId);

        // reassing node ID for next loop iteration
        nodeId = parentNode;
        parentNode = parentNodeId(nodeId);
    }
}

void Heap::fixHeapDown(uint32_t nodeId)
{
    // keep fixing while given node has siblings
    // in Heap node has siblings if at least his left sibling node exists
    while(leftSiblingExists(nodeId))
    {
        if(rightSiblingExists(nodeId))
        {
            // if right sibling node exists we need to choose the one that holds larger value for the swap
            int32_t leftSiblingValue = nodeValue(leftSiblingNodeId(nodeId));
            int32_t rightSiblingValue = nodeValue(rightSiblingNodeId(nodeId));

            if(leftSiblingValue > rightSiblingValue)
            {
                if(leftSiblingValue > nodeValue(nodeId))
                {
                    // left sibling has larger value - swap and reassing node ID for next interation
                    swapNodeValues(leftSiblingNodeId(nodeId), nodeId);
                    nodeId = leftSiblingNodeId(nodeId);
                }
                else
                {
                    // Heap structure is intact - no further fix needed
                    return;
                }
            }
            else
            {
                if(rightSiblingValue > nodeValue(nodeId))
                {
                    // right sibling has larger value - swap and reassing node ID for next interation
                    swapNodeValues(rightSiblingNodeId(nodeId), nodeId);
                    nodeId = rightSiblingNodeId(nodeId);
                }
                else
                {
                    // Heap structure is intact - no further fix needed
                    return;
                }
            }
        }
        else
        {
            if(nodeValue(leftSiblingNodeId(nodeId)) > nodeValue(nodeId))
            {
                // node has only one sibling, just swap values
                swapNodeValues(leftSiblingNodeId(nodeId), nodeId);
            }

            nodeId = leftSiblingNodeId(nodeId);
        }
    }
}

void Heap::add(int32_t value)
{
    extendCapacityIfNeeded();

    // add new leaf node at the Heap lowest level
    uint32_t newNodeId = size++;
    tab[newNodeId] = value;

    // start fixing Heap upwards
    fixHeapUp(newNodeId);
}

bool Heap::remove(uint32_t index)
{
    // check if index is valid
    if(index >= size)
    {
        return false;
    }

    // overwrite node value pointed by index with last leaf value
    int32_t lastValueInHeap = nodeValue(size - 1);
    tab[index] = lastValueInHeap;

    // start fixing Heap downwards
    size--;
    fixHeapDown(index);

    // set Heap to default if last element was removed
    if(isEmpty())
    {
        clear();
    }

    return true;
}

bool Heap::search(int32_t value)
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

uint32_t Heap::getIndex(int32_t value)
{
    for(uint32_t it = 0; it < size; ++it)
    {
        if(tab[it] == value)
        {
            return it;
        }
    }

    return invalidIndex;
}

int32_t Heap::get(uint32_t index)
{
    alignOutOfRangeIndexToSize(index);

    if(index == size)
    {
        index--;
    }

    return tab[index];
}

void Heap::display()
{
    if(isEmpty())
    {
        std::cout << "Kopiec jest pusty." << std::endl;
    }
    else
    {
        std::cout << std::endl << "Forma drzewiasta: " << std::endl;
        displayTree("", "", 0);

        std::cout << std::endl;
        std::cout << "Rozmiar kopca: " << size << "/" << capacity << std::endl << std::endl;

        std::cout << "Forma tablicowa: " << std::endl;
        for(uint32_t it = 0; it < size; ++it)
        {
            std::cout << tab[it] << " ";
        }
    }
}

void Heap::displayTree(std::string branchBody, std::string branchEnd, uint32_t nodeIndex)
{
    // I have used available solution from internet: https://eduinf.waw.pl/inf/alg/001_search/0113.php

    std::string branch;
    std::string childRightBranchSymbol,
                childLeftBranchSymbol,
                childParentBranchExtensionSymbol;

    childRightBranchSymbol = childLeftBranchSymbol = childParentBranchExtensionSymbol = "   ";
    childRightBranchSymbol              = "r--";
    childLeftBranchSymbol               = "L--";
    childParentBranchExtensionSymbol[0] = '|';

    if(nodeIndex < size)
    {
        branch = branchBody;
        if(branchEnd == childRightBranchSymbol)
        {
            branch[branch.length() - 3] = ' ';
        }
        displayTree(branch + childParentBranchExtensionSymbol, childRightBranchSymbol, rightSiblingNodeId(nodeIndex));

        branch = branch.substr(0, branchBody.length() - 3);
        std::cout << branch << branchEnd << "(" << tab[nodeIndex] << ")" << std::endl;

        branch = branchBody;
        if(branchEnd == childLeftBranchSymbol)
        {
            branch[branch.length() - 3] = ' ';
        }
        displayTree(branch + childParentBranchExtensionSymbol, childLeftBranchSymbol, leftSiblingNodeId(nodeIndex));
    }
}
