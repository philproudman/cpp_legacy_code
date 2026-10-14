#pragma once
#include "Order.hpp"

class FetchOrder {
public:
    Order fetchOrder(int orderId);

};

class ShippingCalculator {

public:

    ShippingCalculator(FetchOrder& fetchOrder)
    : m_fetchOrder(fetchOrder)
    {}


    double calculateShipping(int orderId);

private:
    FetchOrder& m_fetchOrder;
};
