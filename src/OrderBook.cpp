#include "../include/OrderBook.h"
void OrderBook::addOrder(const Order& order) {
    if (order.getSide() == Side::Buy) {
        buyBook[order.getPrice()].push_back(order);
    } else {
        sellBook[order.getPrice()].push_back(order);
    }
}