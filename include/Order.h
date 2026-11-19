
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

enum class OrderType
{
    Limit,
    Market
};

class Order
{
    OrderId id;
    Side side;
    int price;
    int quantity;
    uint64_t timestamp;
    OrderType type;

public:
    Order(OrderId id,
          Side side,
          OrderType type,
          int price,
          int quantity,
          uint64_t timestamp)
        : id(id),
          side(side),
          price(price),
          quantity(quantity),
          timestamp(timestamp),
          type(type)
    {
        if (type == OrderType::Limit && price <= 0)
        {
            throw std::invalid_argument(
                "Limit order price must be positive");
        }

        if (type == OrderType::Market && price != 0)
        {
            throw std::invalid_argument(
                "Market order price must be zero");
        }

        if (quantity <= 0)
        {
            throw std::invalid_argument(
                "Quantity must be positive");
        }
    }

    OrderId getId() const
    {
        return id;
    }

    Side getSide() const
    {
        return side;
    }

    OrderType getType() const
    {
        return type;
    }

    int getPrice() const
    {
        return price;
    }

    int getQuantity() const
    {
        return quantity;
    }

    uint64_t getTimestamp() const
    {
        return timestamp;
    }

    void reduceQuantity(int amount)
    {
        if (amount < 0 || amount > quantity)
        {
            throw std::invalid_argument("Invalid fill quantity");
        }

        quantity -= amount;
    }

    void setQuantity(int newQuantity)
    {
        if (newQuantity <= 0)
        {
            throw std::invalid_argument(
                "Quantity must be positive");
        }

        quantity = newQuantity;
    }
};

#endif
