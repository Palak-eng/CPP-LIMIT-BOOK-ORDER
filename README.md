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
* `Order` class
* Strongly typed `Side` enum (`Buy` / `Sell`)
* Type-safe order identifiers using `uint64_t`
* Constructor-based validation
* Exception handling for invalid orders
* Getter methods with `const` correctness
* Encapsulation using private data members

### In progress

* `OrderBook` implementation
* Buy and sell book data structures
* Order insertion logic
* Book visualization (`printBook()`)

## Project structure

```
cpp-limit-order-book/
│
├── include/
│   ├── Order.h
│   └── OrderBook.h
│
├── src/
│   ├── main.cpp
│   └── OrderBook.cpp
│
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

## Planned data structures

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
g++ src/main.cpp -o order_test
./order_test
```

## Roadmap

* [x] Order class
* [ ] OrderBook
* [ ] Limit order insertion
* [ ] Price-time priority
* [ ] Matching engine
* [ ] Partial fills
* [ ] Order cancellation
* [ ] Order modification
* [ ] GoogleTest integration
* [ ] Performance benchmarks

## Educational focus

This project is being developed as a learning exercise in modern C++, STL, object-oriented design, and backend systems engineering. The emphasis is on understanding every design decision rather than simply implementing functionality.
