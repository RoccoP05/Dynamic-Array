# Custom C++ Integer Vector Library

A robust, memory-managed dynamic array implementation in C++ designed to replicate the core functionality of `std::vector<int>`. This project focuses on **amortized analysis**, **manual memory management**, and **exception handling**. 

## Key Features

* **Dynamic Resizing:** Implements an  amortized `push_back` strategy by doubling capacity upon overflow.
* **Memory Safety:** Utilizes a custom destructor to prevent memory leaks and handles dynamic allocation via `new[]` and `delete[]`.
* **Bounds Checking:** Includes comprehensive error handling using `std::out_of_range` exceptions for the `at()`, `insert()`, and `erase()` methods.
* **Dual Interface:** Provides both `const` and non-`const` accessors to support read-only and mutable data operations. 

## Technical Implementation

The library manages an internal heap-allocated array. When the `_size` exceeds `_capacity`, the vector reallocates to a larger block of memory.

### Complexity Analysis

| Operation | Time Complexity | Details |
| --- | --- | --- |
| `push_back` |  Amortized | Average case is constant;  only during reallocation. |
| `insert` |  | Requires shifting elements to the right. |
| `erase` |  | Requires shifting elements to the left. |
| `at()` / `[]` |  | Direct memory access via index. |

## Project Structure

* `IntVector.h`: Class definition, including private helper functions for memory expansion.
* `IntVector.cpp`: Implementation of logic, including memory allocation and bounds checking. 
* `main.cpp`: (Recommended) Unit tests verifying edge cases like empty vectors and maximum capacity.

## How to Use

```cpp
#include "IntVector.h"

int main() {
    IntVector myVec(5, 10); // Initialize with size 5, value 10
    myVec.push_back(20);    // Automatically expands if capacity is reached
    
    try {
        int value = myVec.at(10); // Throws out_of_range exception
    } catch (const std::out_of_range& e) {
        // Handle error
    }
    
    return 0;
}

