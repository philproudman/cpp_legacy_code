#include "InternationalShipping.hpp"

double InternationalShipping::calculateShippingCost(Order &order)
{
    return order.weightKg * 1.5;
}
