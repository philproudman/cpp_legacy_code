#pragma once
#include "Order.hpp"

class FetchOrder {
public:
    Order fetchOrder(int orderId);
};

class ShippingCalculator {
public:
    double calculateShipping(int orderId);

};
