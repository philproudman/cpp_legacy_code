#include "ShippingCalculator.hpp"
#include "Order.hpp"
#include "IShipping.hpp"

#include <iostream>
#include <map>

double ShippingCalculator::calculateShipping(int orderId) {
    try {
        Order order = m_fetchOrder.fetchOrder(orderId);

        auto shipping = m_shippingLookup.find(order.shippingType);
        if (shipping != m_shippingLookup.end()) return shipping->second->calculateShippingCost(order);

        throw std::runtime_error(
            "Unknown shipping type: " + order.shippingType
        );

    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
        return -1;
    }
}

