#include <Application/Menu/Actions/PerformMeasurements.hpp>


PerformMeasurements::PerformMeasurements()
    : generationsCount(100)
    , graphTypes(2)
    , instanceSizes(10, 20, 30, 50, 70, 80, 100)
    , densities( { 20.0, 60.0, 99.0 } )
{ }