# C Data Structures Library

A simple C library implementing basic data structures with
unit tests and CI.

Features
- Queue implementation
- Stack implementation
- Linked list implementation
- CMake build system
- Unit tests using assert
- GitHub Actions CI

Build
-----
```bash
cmake -S . -B build
cmake --build build
```

Run Tests
---------
```bash
ctest --test-dir build
```

Project Structure
-----------------
```
src/        implementation
include/    public headers
tests/      unit tests
```

Notes
-----
- Tests are silent by design.
- If all asserts pass, no output is produced.
- A failing assert will abort the program.
