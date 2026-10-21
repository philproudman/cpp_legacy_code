#include "StandardShipping.hpp"

double StandardShipping::calculateShippingCost(Order &order)
{
    return order.weightKg * 0.5;
}
