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

Status below reflects the code as it exists in the working tree, including the
not-yet-committed `OrderType` changes in `include/Order.h` and `main.cpp`.

In short: the order model, book, two-sided matching, and partial fills are done;
the rest of the original goals (market orders, order lifecycle operations, trade
reporting, tests, benchmarks) are still open.

### Completed

* Project structure (`include/`, `src/`, `main.cpp`)
* `Order` class with `reduceQuantity()` for applying fills
* Strongly typed `Side` enum (`Buy` / `Sell`)
* Type-safe order identifiers using `uint64_t`
* Constructor-based validation (positive price and quantity)
* Exception handling for invalid orders and invalid fill quantities
* Getter methods with `const` correctness
* Encapsulation using private data members
* `OrderBook` with separate buy and sell books
* Limit order insertion
* Price-time priority via `std::map` + `std::deque`
* Book visualization (`printBook()`)
* Two-sided matching engine:
  * Incoming buy orders vs resting sell orders
  * Incoming sell orders vs resting buy orders
* Partial fills via quantity reduction
* Fully filled orders are removed and empty price levels are erased from the book
* Runnable demo in `main.cpp`; builds with a single `g++` command

### Defined but not yet used

* `OrderType` enum (`Limit` / `Market`) exists and is stored on `Order`, but
  `addOrder()` / `matchOrder()` currently treat every order the same way. Market
  orders are not executed specially and cannot use a zero price because the
  `Order` constructor requires a positive price.

### Not yet implemented

* Market order execution
* Trade reporting (fills are applied silently)
* Order cancellation and modification (there is no ID-to-order lookup yet)
* Best bid/ask or order-query APIs
* Unit tests (GoogleTest) and performance benchmarks
* Build automation (CMake/Make); `engineering_notes.md` is currently empty

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
├── engineering_notes.md   (placeholder, currently empty)
└── README.md
```

## Order model

Each order contains:

* Order ID
* Side (Buy / Sell)
* Price (stored in paise as an integer)
* Quantity
* Timestamp
* Order type (`Limit` / `Market`)

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

1. The best available price level is checked (`sellBook.begin()` for buy orders, `buyBook.begin()` for sell orders).
2. If the incoming order crosses (buy price >= best ask, or sell price <= best bid), it trades against the oldest order at that level.
3. The fill quantity is `min(incoming quantity, resting quantity)`; both quantities are reduced accordingly.
4. Orders fully filled are removed; empty price levels are erased from the map.
5. Any remaining quantity rests on the book at its limit price.

Both matching directions are implemented. Fills are still silent: no trade records
or execution callbacks are produced yet.

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
* [x] Matching engine (buy and sell sides)
* [x] Partial fills
* [x] `OrderType` enum declared and stored on `Order`
* [ ] Market order execution (`OrderType::Market` is defined but unused)
* [ ] Trade reporting
* [ ] Order cancellation
* [ ] Order modification
* [ ] GoogleTest integration
* [ ] Performance benchmarks
* [ ] Build system (CMake/Make)

## Educational focus

This project is being developed as a learning exercise in modern C++, STL, object-oriented design, and backend systems engineering. The emphasis is on understanding every design decision rather than simply implementing functionality.
