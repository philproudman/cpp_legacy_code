#include "src/ShippingCalculator.hpp"
#include "src/SalesLedger.hpp"
#include "src/StandardShipping.hpp"
#include "src/ExpressShipping.hpp"
#include "src/OvernightShipping.hpp"
#include "src/InternationalShipping.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <orderId>" << std::endl;
        return 1;
    }

    int orderId;
    try {
        orderId = std::stoi(argv[1]);
    } catch (const std::exception&) {
        std::cerr << "Invalid orderId: " << argv[1] << std::endl;
        return 1;
    }
    SalesLedger fetchOrder;

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

    ShippingCalculator calculator (fetchOrder, shippingLookup);
    const double cost = calculator.calculateShipping(orderId);
    std::cout << "Order " << orderId << " shipping cost: " << cost << std::endl;

    return 0;
}
