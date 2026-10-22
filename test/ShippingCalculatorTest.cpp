#include <gtest/gtest.h>
#include "ShippingCalculator.hpp"
#include "Order.hpp"
#include "StandardShipping.hpp"
#include "ExpressShipping.hpp"
#include "OvernightShipping.hpp"
#include "InternationalShipping.hpp"

class MockSalesLedger : public ISalesLedger {
public:
    MockSalesLedger(Order order)
        : m_order(order){}

    MockSalesLedger() = default;

    Order fetchOrder(int orderId) override {
        return m_order;
    }

private:
    Order m_order;
};

class ShippingCalculatorTest : public ::testing::Test {
protected:
     StandardShipping m_standardShipping;
    ExpressShipping m_expressShipping;
    OvernightShipping m_overnightShipping;
    InternationalShipping m_internationalShipping;

   std::map<std::string, IShipping*> m_shippingLookup = {
            { "STANDARD", &m_standardShipping },
            { "EXPRESS", &m_expressShipping },
            { "OVERNIGHT", &m_overnightShipping },
            { "INTERNATIONAL", &m_internationalShipping }
        };
};

TEST_F(ShippingCalculatorTest, CalculateShippingForStandardOrder) {
    MockSalesLedger ledger(Order{"STANDARD", 2.5, 100.0});
    ShippingCalculator calculator(ledger, m_shippingLookup);
    
    double shipping = calculator.calculateShipping(1);
    
    ASSERT_EQ(shipping, 1.25);
}

TEST_F(ShippingCalculatorTest, CalculateShippingForExpressOrder) {
    MockSalesLedger ledger(Order{"EXPRESS", 5.0, 500.0});
    ShippingCalculator calculator(ledger, m_shippingLookup);
    
    double shipping = calculator.calculateShipping(1);
    
    ASSERT_EQ(shipping, 54.0);
}

TEST_F(ShippingCalculatorTest, CalculateShippingForOvernightOrder) {
    MockSalesLedger ledger(Order{"OVERNIGHT", 1.0, 50.0});
    ShippingCalculator calculator(ledger, m_shippingLookup);
    
    double shipping = calculator.calculateShipping(1);
    
    ASSERT_EQ(shipping, 26.2);
}

TEST_F(ShippingCalculatorTest, CalculateShippingForInternational) {
    MockSalesLedger ledger(Order{"INTERNATIONAL", 3.0, 0.0});
    ShippingCalculator calculator(ledger, m_shippingLookup);

    double shipping = calculator.calculateShipping(1);

    ASSERT_EQ(shipping, 4.5);
}