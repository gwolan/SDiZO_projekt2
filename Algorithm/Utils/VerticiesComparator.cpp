#include <Algorithm/Utils/VerticiesComparator.hpp>


VerticiesComparator::VerticiesComparator(const std::vector<int32_t>& pathCosts)
    : costs(pathCosts)
{ }

bool VerticiesComparator::operator()(const uint32_t l, const uint32_t r) const
{
    return static_cast<uint32_t>(costs[l]) < static_cast<uint32_t>(costs[r]);
}
