#include <iostream>
#include "include/Order.h"
#include "include/OrderBook.h"

int main()
{
    try
    {
        OrderBook book;

       Order buyOrder(1, Side::Buy, OrderType::Limit, 100, 10, 1);
      Order sellOrder(2, Side::Sell, OrderType::Limit, 100, 6, 2);

        book.addOrder(buyOrder);
        book.addOrder(sellOrder);
        

        // Display final order book
        book.printBook();
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Invalid order: " << e.what() << "\n";
    }

    return 0;
}