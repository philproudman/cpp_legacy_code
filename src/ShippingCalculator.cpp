#include "ShippingCalculator.hpp"
#include "Order.hpp"
#include "StandardShipping.hpp"
#include "ExpressShipping.hpp"
#include "OvernightShipping.hpp"
#include "InternationalShipping.hpp"

#include <iostream>
#include <map>

double ShippingCalculator::calculateShipping(int orderId) {
    try {
        Order order = m_fetchOrder.fetchOrder(orderId);

        StandardShipping standardShipping;
        ExpressShipping expressShipping;
        OvernightShipping overnightShipping;
        InternationalShipping internationalShipping;

        std::map<std::string, IShipping*> shippingLookup = {
            { "STANDARD", &standardShipping },
            { "EXPRESS", &expressShipping },
            { "OVERNIGHT", &overnightShipping },
            { "INTERNATIONAL", &internationalShipping }
        };

        auto shipping = shippingLookup.find(order.shippingType);
        if (shipping != shippingLookup.end()) return shipping->second->calculateShippingCost(order);

        throw std::runtime_error(
            "Unknown shipping type: " + order.shippingType
        );

    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
        return -1;
    }
}

