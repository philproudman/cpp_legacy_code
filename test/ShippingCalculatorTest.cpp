#include <gtest/gtest.h>
#include "ShippingCalculator.hpp"
#include "Order.hpp"

// Mock implementation of ISalesLedger for testing
class MockSalesLedger : public ISalesLedger {
public:
    Order fetchOrder(int orderId) override {
        if (orderId == 1) {
            return Order{"STANDARD", 2.5, 100.0};
        } else if (orderId == 2) {
            return Order{"EXPRESS", 5.0, 500.0};
        } else if (orderId == 3) {
            return Order{"OVERNIGHT", 1.0, 50.0};
        }
        return Order{"STANDARD", 0.0, 0.0};
    }
};

class ShippingCalculatorTest : public ::testing::Test {
protected:
    MockSalesLedger ledger;
    ShippingCalculator calculator{ledger};
};

TEST_F(ShippingCalculatorTest, CalculateShippingForStandardOrder) {
    // Arrange
    int orderId = 1;
    
    // Act
    double shipping = calculator.calculateShipping(orderId);
    
    // Assert
    ASSERT_GT(shipping, 0.0);
}

TEST_F(ShippingCalculatorTest, CalculateShippingForExpressOrder) {
    // Arrange
    int orderId = 2;
    
    // Act
    double shipping = calculator.calculateShipping(orderId);
    
    // Assert
    ASSERT_GT(shipping, 0.0);
}

TEST_F(ShippingCalculatorTest, CalculateShippingForOvernightOrder) {
    // Arrange
    int orderId = 3;
    
    // Act
    double shipping = calculator.calculateShipping(orderId);
    
    // Assert
    ASSERT_GT(shipping, 0.0);
}
