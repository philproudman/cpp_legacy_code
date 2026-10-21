#include "IShipping.hpp"

class StandardShipping : public IShipping  {
public:
    double calculateShippingCost(Order &order);
};