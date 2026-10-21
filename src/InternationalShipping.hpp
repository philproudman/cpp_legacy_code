#include "IShipping.hpp"

class InternationalShipping : public IShipping {
public:
   double calculateShippingCost(Order &order);
};