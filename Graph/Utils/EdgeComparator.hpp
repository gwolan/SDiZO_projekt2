#pragma once

#include <Graph/Utils/Edge.hpp>


struct EdgeComparator
{
    bool operator()(const Edge& el, const Edge& er) const;
};
