#include "IShipping.hpp"

class ExpressShipping : public IShipping {
public:
    double calculateShippingCost(Order &order);
};