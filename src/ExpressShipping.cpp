#include "ExpressShipping.hpp"

double ExpressShipping::calculateShippingCost(Order &order)
{
    return order.weightKg * 0.8 + order.distanceKm * 0.1;
}
