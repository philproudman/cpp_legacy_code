#pragma once
#include "Order.hpp"
#include "ISalesLedger.hpp"

class ShippingCalculator {

public:

    ShippingCalculator(ISalesLedger& fetchOrder)
    : m_fetchOrder(fetchOrder)
    {}

    double calculateShipping(int orderId);

private:
    ISalesLedger& m_fetchOrder;
};
