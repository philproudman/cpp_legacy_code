#include "IShipping.hpp"

class OvernightShipping : public IShipping {
public:
    double calculateShippingCost(Order &order);
};