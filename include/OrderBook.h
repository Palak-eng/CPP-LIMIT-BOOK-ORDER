#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <map>
#include <deque>
#include "Order.h"


class OrderBook {
    private:
        std ::map<int, std::deque<Order>, std ::greater<int>> buyBook;
        std::map<int, std ::deque<Order>> SellBook;

    public:
         void addOrder(const Order& order);
};

#endif








