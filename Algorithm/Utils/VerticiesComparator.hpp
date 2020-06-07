#pragma once

#include <cstdint>
#include <vector>


struct VerticiesComparator
{
    VerticiesComparator(const std::vector<int32_t>& pathCosts);

    bool operator()(const uint32_t l, const uint32_t r) const;


    private:
    const std::vector<int32_t>& costs;
};
