#include <iostream>
#include "../include/Order.h"
#include "../include/OrderBook.h"

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
    OrderBook book;

book.addOrder(Order(1, Side::Buy, 100, 50, 1));
book.addOrder(Order(2, Side::Buy, 105, 20, 2));
book.addOrder(Order(3, Side::Buy, 105, 30, 3));
book.addOrder(Order(4, Side::Buy, 95, 10, 4));

book.addOrder(Order(5, Side::Sell, 110, 40, 5));
book.addOrder(Order(6, Side::Sell, 105, 25, 6));
book.addOrder(Order(7, Side::Sell, 110, 15, 7));

book.printBook();

    return 0;
}