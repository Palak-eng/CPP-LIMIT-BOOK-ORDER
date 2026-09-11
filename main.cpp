#include <iostream>
#include "include/Order.h"
#include "include/OrderBook.h"

int main()
{
    try
    {
        OrderBook book;

        Order buy1(1, Side::Buy, 100, 5, 1);
        Order buy2(2, Side::Buy, 100, 5, 2);
        Order sell1(3, Side::Sell, 100, 6, 3);

        book.addOrder(buy1);
        book.addOrder(buy2);
        book.addOrder(sell1);

        // Display final order book
        book.printBook();
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Invalid order: " << e.what() << "\n";
    }

    return 0;
}