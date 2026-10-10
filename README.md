# Arbitrary Precision Calculator in C

## Overview
The Arbitrary Precision Calculator (APC) is a C-based application designed to perform arithmetic operations on large numbers that exceed the standard limits of built-in numeric data types. It uses **doubly linked lists** to store and process digits efficiently.

## Features
- Addition of large numbers
- Subtraction of large numbers
- Multiplication of large numbers
- Division of large numbers
- Doubly linked list-based number representation
- Modular program structure using separate C source files

## Technologies Used
- **Programming Language:** C
- **Data Structure:** Doubly Linked Lists
- **Build Tool:** Makefile
- **Concepts:** Dynamic Memory Allocation, Pointers, Arithmetic Operations

## Project Structure
```text
ArbitraryPrecisionCalculator/
├── main.c
├── apc.h
├── add.c
├── sub.c
├── mul.c
├── div.c
├── list.c
├── disp.c
├── util.c
├── makefile
└── documentation
```

## How to Compile and Run

1. Clone the repository:
   ```bash
   git clone https://github.com/vismaya-pp/arbitrary-precision-calculator.git
   ```

2. Navigate to the project directory:
   ```bash
   cd arbitrary-precision-calculator
   ```

3. Compile the project:
   ```bash
   make
   ```

4. Run the generated executable using the filename specified in your Makefile.

## Learning Outcomes
- Practical implementation of doubly linked lists in C
- Improved understanding of pointers and dynamic memory management
- Modular programming and multi-file compilation
- Handling arithmetic operations on large numbers

## Author
**Vismaya P P**

GitHub: [vismaya-pp](https://github.com/vismaya-pp)
