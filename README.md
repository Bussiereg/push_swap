# Push Swap

Push Swap is a project developed as part of the curriculum at 42 School. It is a sorting algorithm project where the goal is to sort a stack of integers using a set of predefined operations while minimizing the number of moves.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Installation](#installation)
- [Algorithm](#algorithm)

## Introduction

Push Swap aims to implement an efficient sorting algorithm for a stack of integers. The program takes an unsorted stack as input and produces a series of operations that, when applied, would result in a sorted stack. The challenge is to achieve this with the minimum possible number of operations.

## Features

- **Efficient Sorting**: Push Swap implements an efficient sorting algorithm that minimizes the number of operations required to sort the stack.
- **Interactive Visualization**: Optionally, visualize the sorting process step-by-step to understand how the algorithm works.
- **Multiple Input Formats**: Support for various input formats such as arrays, file inputs, or standard input.
- **Error Handling**: Robust error handling to deal with invalid inputs or edge cases.

## Usage

To use Push Swap, follow these steps:

1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Compile the program using the provided Makefile.
4. Run the program with a list of integers as input.

Example:
```bash
./push_swap 3 1 5 2 4

./push_swap 3 1 5 2 4 | ./checker 3 1 5 2 4
```

## Algorithm

Push Swap implements a custom sorting algorithm specifically designed for this project. The algorithm consists of a combination of various sorting techniques, including insertion sort, selection sort, and other optimization strategies.

For detailed information on the algorithm used, refer to the source code and accompanying documentation.
