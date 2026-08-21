#include <iostream>
#include "include/Order.h"
#include "include/OrderBook.h"

int main()
{
    try
    {
        OrderBook book;

        // Existing SELL order
        Order sellOrder(1, Side::Sell, 103, 20, 1);

        // Incoming BUY order
        Order buyOrder(2, Side::Buy, 105, 50, 2);

        // Add orders to the book
        book.addOrder(sellOrder);
        book.addOrder(buyOrder);

        // Display final order book
        book.printBook();
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Invalid order: " << e.what() << "\n";
    }

    return 0;
}