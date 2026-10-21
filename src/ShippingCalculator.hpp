#pragma once
#include "Order.hpp"

class ISalesLedger {
public:
    virtual Order fetchOrder(int orderId) = 0;
};

class SalesLedger : public ISalesLedger {
public:
    Order fetchOrder(int orderId);
};

class ShippingCalculator {

public:

    ShippingCalculator(ISalesLedger& fetchOrder)
    : m_fetchOrder(fetchOrder)
    {}

    double calculateShipping(int orderId);

    double calculateShippingCost(Order &order);

private:
    ISalesLedger& m_fetchOrder;
};
