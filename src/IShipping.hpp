#pragma once

#include "Order.hpp"

class IShipping {
public:
    virtual double calculateShippingCost(Order &order) = 0;
};