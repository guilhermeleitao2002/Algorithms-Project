# Project: Analysis and Synthesis of Algorithms – Project 1

This project involves implementing two related problems using efficient algorithmic techniques. The focus is on computing properties of strictly increasing subsequences within one or two integer sequences.

## Problem Descriptions

### Problem 1: Longest Strictly Increasing Subsequence and Count
- **Objective:**  
  Given a sequence of integers `x = <x₀, x₁, …, xₖ>`, determine:
  - The length of the longest strictly increasing subsequence.
  - The number of distinct subsequences that achieve this maximum length.
  
- **Example:**  
  For the sequence `x = <1, 2, 6, 3, 7>`, there are two maximum subsequences:
  - `<1, 2, 6, 7>`
  - `<1, 2, 3, 7>`
  Both with a length of 4.

### Problem 2: Longest Common Strictly Increasing Subsequence
- **Objective:**  
  Given two sequences of integers `x = <x₀, x₁, …, xₖ>` and `y = <y₀, y₁, …, yₗ>`, compute:
  - The length of the longest common subsequence that is strictly increasing.
  
- **Example:**  
  For sequences `x = <1, 2, 6, 3, 7>` and `y = <1, 2, 4, 7, 3>`, the longest common strictly increasing subsequences are:
  - `<1, 2, 3>`
  - `<1, 2, 7>`
  Both with a length of 3.

## Input and Output Format

- **Input:**
  - The first line contains an integer indicating the problem to solve (1 for Problem 1 and 2 for Problem 2).
  - For Problem 1, one additional line follows with the sequence of integers.
  - For Problem 2, two additional lines follow – one for each sequence.
  - Integers in a sequence are separated by a single space.

- **Output:**
  - **Problem 1:**  
    Two integers separated by a space: the length of the longest subsequence and the number of such subsequences.
  - **Problem 2:**  
    A single integer representing the length of the longest common strictly increasing subsequence.

## Implementation Details

- **Programming Languages:**  
  The project should be implemented preferably in C or C++ for optimal performance. Implementations in Java or Python are also accepted but may encounter efficiency issues on some tests.

- **Compilation Parameters:**  
  - **C++:**  
    ```bash
    g++ -std=c++11 -O3 -Wall file.cpp -lm
    ```
  - **C:**  
    ```bash
    gcc -O3 -ansi -Wall file.c -lm
    ```
  - **Other Languages:**  
    Ensure that the program reads input from standard input and writes output to standard output.

- **Algorithmic Considerations:**  
  - The solution must efficiently handle input sequences within the given constraints.
  - Special attention should be given to memory and time optimization since the evaluation environment restricts these resources.
  - The implementation should strictly adhere to the input/output specifications to ensure that automatic testing (using diff on outputs) correctly validates the solution.

- **Code Structure:**  
  - The code should be modular, well-documented, and structured to separate logic for input parsing, algorithm execution, and output generation.
  - It is recommended to include comments explaining key algorithmic steps, especially for handling the dynamic programming or other efficient methods used to solve the problems.

## Usage

1. **Compilation:**  
   Use the provided commands to compile your solution based on the chosen programming language.
   
2. **Execution:**  
   Run the compiled executable. The program will read from standard input and output the result to standard output.
