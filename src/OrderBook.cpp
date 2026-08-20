#include "../include/OrderBook.h"
#include <iostream>
void OrderBook::addOrder(const Order& order) {
    if (order.getSide() == Side::Buy) {
        buyBook[order.getPrice()].push_back(order);
    } else {
        sellBook[order.getPrice()].push_back(order);
    }
}
void OrderBook::printBook() const {
    std::cout << "\n=====ORDER BOOK=====\n";
    std::cout <<"\nBUY ORDERS:\n";
    for (const auto& kv : buyBook) {
        const int price = kv.first;
        const auto& orders = kv.second;
        for (const auto& order : orders) {
            std::cout << "Order ID: " << order.getId() << ", Price: " << order.getPrice() << ", Quantity: " << order.getQuantity() << ", Timestamp: " << order.getTimestamp() << "\n";
        }
    }
    std::cout <<"\nSELL ORDERS:\n";
    for (const auto& kv : sellBook) {
        const int price = kv.first;
        const auto& orders = kv.second;
        for (const auto& order : orders) {
               std::cout << "Price: " << price
                      << " | ID: " << order.getId()
                      << " | Quantity: " << order.getQuantity()
                      << "\n";
        }
    }

        std::cout << "\n================================\n";
}

