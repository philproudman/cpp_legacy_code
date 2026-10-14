#pragma once
#include "Order.hpp"



class SalesLedger {
public:
    Order fetchOrder(int orderId);

};

class ShippingCalculator {

public:

    ShippingCalculator(SalesLedger& fetchOrder)
    : m_fetchOrder(fetchOrder)
    {}


    double calculateShipping(int orderId);

private:
    SalesLedger& m_fetchOrder;
};
