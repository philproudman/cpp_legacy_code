#pragma once
#include "Order.hpp"
#include "ISalesLedger.hpp"
#include "IShipping.hpp"

#include <map>

class ShippingCalculator {

public:

    ShippingCalculator(ISalesLedger& fetchOrder,  std::map<std::string, IShipping*>& shippingLookup)
    : m_fetchOrder(fetchOrder), m_shippingLookup(shippingLookup)
    {}

    double calculateShipping(int orderId);

private:
    ISalesLedger& m_fetchOrder;
    std::map<std::string, IShipping*>& m_shippingLookup;
};
