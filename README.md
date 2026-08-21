# C++ limit order book

A high-performance limit order book and matching engine implemented in modern C++. The project is being built from scratch to simulate the core data structures and algorithms used by electronic trading systems.

## Project goal

The goal is to implement a simplified exchange matching engine that supports:

* Price-time priority
* Buy and sell order books
* Limit order insertion
* Market order execution
* Partial fills
* Order cancellation and modification
* Unit testing with GoogleTest
* Performance-oriented C++ design

This project is intended as a systems programming and backend engineering portfolio project.

## Current progress

### Completed

* Project structure
* `Order` class (with `reduceQuantity()` for applying fills)
* Strongly typed `Side` enum (`Buy` / `Sell`)
* Type-safe order identifiers using `uint64_t`
* Constructor-based validation
* Exception handling for invalid orders
* Getter methods with `const` correctness
* Encapsulation using private data members
* `OrderBook` with separate buy and sell books
* Limit order insertion
* Book visualization (`printBook()`)
* Basic matching engine (incoming buy orders vs resting sell orders)
* Partial fills via quantity reduction
* Fully-filled price levels are erased from the book

### In progress

* Sell-side matching (incoming sell orders vs resting buy orders)
* Trade reporting (fills are currently applied silently)
* Order cancellation and modification

## Project structure

```
limit-order-book/
│
├── include/
│   ├── Order.h
│   └── OrderBook.h
│
├── src/
│   └── OrderBook.cpp
│
├── main.cpp
├── .gitignore
└── README.md
```

## Order model

Each order contains:

* Order ID
* Side (Buy / Sell)
* Price (stored in paise as an integer)
* Quantity
* Timestamp

Prices are stored as integers rather than floating-point values to avoid precision errors in financial calculations.

## Design principles

The project emphasizes:

* Encapsulation
* Type safety
* Immutable object validity through constructor validation
* STL-based data structures
* Clean separation between interface and implementation

## Matching engine

An incoming limit order is matched against the opposite side of the book before resting:

1. The best available price level is checked (`sellBook.begin()` for buy orders).
2. If the incoming order crosses (buy price >= best ask), it trades against the oldest order at that level.
3. The fill quantity is `min(incoming quantity, resting quantity)`; both quantities are reduced accordingly.
4. Orders fully filled are removed; empty price levels are erased from the map.
5. Any remaining quantity rests on the book at its limit price.

## Data structures

Buy side:

```
std::map<int, std::deque<Order>, std::greater<int>>
```

Sell side:

```
std::map<int, std::deque<Order>>
```

This design naturally supports price-time priority.

## Build

Compile the project with a C++17 compiler.

Example:

```bash
g++ -std=c++17 main.cpp src/OrderBook.cpp -o order_test
./order_test
```

## Roadmap

* [x] Order class
* [x] OrderBook
* [x] Limit order insertion
* [x] Price-time priority
* [ ] Matching engine (buy side working, sell side pending)
* [x] Partial fills
* [ ] Order cancellation
* [ ] Order modification
* [ ] GoogleTest integration
* [ ] Performance benchmarks

## Educational focus

This project is being developed as a learning exercise in modern C++, STL, object-oriented design, and backend systems engineering. The emphasis is on understanding every design decision rather than simply implementing functionality.
