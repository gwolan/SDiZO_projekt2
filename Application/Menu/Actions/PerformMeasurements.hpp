#pragma once

#include <vector>
#include <cstdint>
#include <Application/Menu/Actions/BaseAction.hpp>


class PerformMeasurements : public BaseAction
{
    public:
    PerformMeasurements() = default;
    ~PerformMeasurements() = default;


    private:
    const uint32_t generationsCount;
    const uint32_t graphTypes;
    const std::vector<uint32_t> instanceSizes;
    const std::vector<double> densities;
};
