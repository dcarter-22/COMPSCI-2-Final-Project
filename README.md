# Library Management System (COMPSCI‑2 Final Project)

## Overview
This project is a **C++** app that manages a small library:  
* books are stored in a binary search tree (BST) keyed by *title*,  
* members are held in an `unordered_map`,  
* pending returns are queued,  
* transactions are logged.

Core C++ concepts demonstrated:

| Concept | Where used |
|---------|------------|
| **Classes & Inheritance** | `Book`, `Member`, `Transaction`, `Library` (`Library` inherits from `BSTBase`) |
| **Pointers & Dynamic Memory** | BST nodes store `Book*` and are managed manually |
| **Sorting & Searching** | In‑order BST traversal plus a standalone quicksort routine in `sort_utils.cpp` |
| **File I/O (Streams)** | `loadBooks()`, `saveBooks()`, `loadMembers()`… |
| **Data Structures** | Binary search tree, queue (`<queue>`), vector |
| **Advanced C++** | Smart pointers (`std::unique_ptr`) in tests, templates in `BST.h` |

## Build

```bash
# Linux / macOS / WSL
g++ -std=c++17 -I./src src/*.cpp -o bin/library
./bin/library
```

For Windows (MinGW):

```bash
g++ -std=c++17 -I./src src/*.cpp -o bin\library.exe
.\bin\library.exe
```

## Test

```bash
g++ -std=c++17 -I./src src/*.cpp tests/test_main.cpp -o bin/tests
./bin/tests
```

## File layout
```
library_system/
├── README.md
├── report.md
├── src/
│   ├── main.cpp
│   ├── Book.h / Book.cpp
│   ├── Member.h / Member.cpp
│   ├── Transaction.h / Transaction.cpp
│   ├── BST.h / BST.cpp
│   ├── Queue.h / Queue.cpp
│   ├── Library.h / Library.cpp
│   └── sort_utils.cpp
└── tests/
    └── test_main.cpp
```

## Sample run
```
Welcome to the Library!
1. Add book
2. Add member
3. Borrow book
4. Request return
5. Process returns
6. List books by title
0. Quit
➜
```

## Author
Damien Carter ‑ COMPSCI‑2 – May 2025
