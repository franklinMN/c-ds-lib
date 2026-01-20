# C Data Structures Library

A small, clean C library implementing fundamental data structures with
a strong focus on correctness, testing, and build automation.

This project is intentionally built step by step to demonstrate
real-world C development practices: modular design, generic APIs,
CTest-based testing, and CI using GitHub Actions.

---

## Features

- Singly Linked List
- Stack (built on top of list)
- Queue
- Two versions:
  - v1: int-only implementation
  - v2: fully generic (void*) implementation
- Unit tests using assert
- CMake build system
- Continuous Integration with GitHub Actions

---

## Repository Structure
```bash
.
├── include/
│   └── ds/
│       ├── list.h
│       ├── stack.h
│       └── queue.h
├── src/
│   ├── list.c
│   ├── stack.c
│   └── queue.c
├── tests/
│   ├── test_list_generic.c
│   ├── test_stack_generic.c
│   └── test_queue_generic.c
├── .github/
│   └── workflows/
│       └── ci.yml
├── CMakeLists.txt
└── README.md
```
---

## Versions & Branches

- main
  - v1.0.0-int
  - int-based list, stack, and queue
  - stable release (tagged)

- generic-ds
  - v2.x (current development)
  - generic void* data structures
  - ownership-aware API
  - active CI

---

## Design Principles

- No hidden allocations for user data
- Data structures store pointers only
- Clear ownership rules
- Minimal abstractions
- Simple, testable APIs

---

## Generic API Design (v2)

### Ownership Rules

- User owns all data passed into the data structures
- Library stores void* pointers
- Optional free_fn allows automatic cleanup during destroy
- Popped elements are returned to the user and must be freed by the user

---

## Build Instructions

### Requirements

- C compiler (gcc / clang)
- CMake >= 3.15

### Build

cmake -S . -B build
cmake --build build

---

## Running Tests Locally

cd build
ctest --output-on-failure

---

## Continuous Integration

GitHub Actions automatically:
- builds the project
- runs all tests
- fails on any assertion error

Workflow file:
.github/workflows/ci.yml

---

## Roadmap

- v1.0.0 — int-only data structures (completed)
- v2.0.0 — generic void* data structures (completed)
- v2.x   — documentation & polish
- v3.x   — iterators, size tracking, extensions

---

## License

MIT License
