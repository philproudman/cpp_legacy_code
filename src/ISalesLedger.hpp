#pragma once

#include "Order.hpp"

class ISalesLedger {
public:
    virtual Order fetchOrder(int orderId) = 0;
};
