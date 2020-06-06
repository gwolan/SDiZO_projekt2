#include <Graph/Utils/EdgeComparator.hpp>


bool EdgeComparator::operator()(const Edge& el, const Edge& er) const
{
    return el.weight > er.weight;
}