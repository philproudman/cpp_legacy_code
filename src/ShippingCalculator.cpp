#include "ShippingCalculator.hpp"
#include "Order.hpp"
#include "StandardShipping.hpp"
#include "ExpressShipping.hpp"

#include <iostream>


double ShippingCalculator::calculateShipping(int orderId) {
    try {
        Order order = m_fetchOrder.fetchOrder(orderId);

        if (order.shippingType == "STANDARD") {
            return StandardShipping().calculateShippingCost(order);
        }

        if (order.shippingType == "EXPRESS") {
            return ExpressShipping().calculateShippingCost(order);
        }

        if (order.shippingType == "OVERNIGHT") {
            return order.weightKg * 1.2 + 25;
        }

        if (order.shippingType == "INTERNATIONAL"){
            return order.weightKg * 1.5;
        }

        throw std::runtime_error(
            "Unknown shipping type: " + order.shippingType
        );

    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
        return -1;
    }
}

