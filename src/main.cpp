#include <iostream>
#include "../include/Order.h"

int main() {
    try {
        Order order(1, Side::Buy, 10025, 50, 123456);

        std::cout << "Order created successfully\n";
        std::cout << "Price: " << order.getPrice() << "\n";
        std::cout << "Quantity: " << order.getQuantity() << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}