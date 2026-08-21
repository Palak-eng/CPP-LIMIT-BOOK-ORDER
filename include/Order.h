#ifndef ORDER_H
#define ORDER_H

#include <cstdint>
#include <stdexcept>
using OrderId = uint64_t;
enum class Side
{
    Buy,
    Sell
};

class Order
{
    OrderId id;
    Side side;
    int price;
    int quantity;
    uint64_t timestamp;

public:
     Order(OrderId id,
     Side side,
     int price,
     int quantity,
      uint64_t timestamp)
      : id(id),
        side(side),
         price(price),
          quantity(quantity),
          timestamp(timestamp)

     {
        if (price <= 0) {
            throw std::invalid_argument("Price must be positive");
        }

        if (quantity <= 0) {
            throw std::invalid_argument("Quantity must be positive");
        }
    }
    OrderId getId() const {
        return id;
    }

    Side getSide() const {
        return side;
    }

    int getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }

    uint64_t getTimestamp() const {
        return timestamp;
    }
    void reduceQuantity(int amount){
        quantity-=amount;
    }
};

#endif





