#pragma once

#include "ISalesLedger.hpp"

class SalesLedger : public ISalesLedger {
public:
    Order fetchOrder(int orderId);
};