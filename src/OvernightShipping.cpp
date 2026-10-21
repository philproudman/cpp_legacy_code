#include "OvernightShipping.hpp"

double OvernightShipping::calculateShippingCost(Order &order)
{
    return order.weightKg * 1.2 + 25;
}
