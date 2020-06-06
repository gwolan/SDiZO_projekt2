#include <Graph/Utils/Edge.hpp>


bool Edge::operator==(const Edge& other)
{
    return other.start == start &&
           other.end   == end;
}
