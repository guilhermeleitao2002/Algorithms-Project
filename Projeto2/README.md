# Project 2: Genealogical Tree Analysis

This project involves processing a directed graph that represents a genealogical tree. The implementation focuses on two main tasks: validating the tree structure and computing the nearest common ancestors (NCAs) of two specified nodes.

## Problem Overview

- **Genealogical Tree Validation:**  
  The input graph must form a valid genealogical tree. In this context:
  - Each node represents a person.
  - A node may have zero, one, or two parents.
  - The parent-child relationships must form a proper tree structure without cycles or inconsistencies.

- **Nearest Common Ancestors (NCA):**  
  For two given nodes `v1` and `v2`:
  - An ancestor of a node is any node that can reach it via a sequence of directed edges.
  - A node is considered an NCA if it is a common ancestor of both `v1` and `v2` and there is no descendant of that node which is also a common ancestor.
  - The solution must handle cases where there are multiple NCAs, outputting them in ascending order, or indicate if no common ancestors exist.

## Input and Output Specifications

- **Input Format:**
  - The first line contains two integers representing the identifiers of nodes `v1` and `v2` for which NCAs are to be computed.
  - The second line contains two integers: `n` (number of vertices) and `m` (number of edges).
  - The following `m` lines each contain two integers `x` and `y`, meaning that `y` is a child of `x`.

- **Output Format:**
  - If the graph does not form a valid genealogical tree, the program outputs `0`.
  - If the tree is valid:
    - Output all NCAs of the given nodes, sorted in ascending order, separated by a single space with a trailing space.
    - If no common ancestors exist, output `-`.

## Implementation Details

- **Preferred Languages:**  
  The solution should be implemented preferably in C or C++ for performance reasons. Implementations in Java or Python are allowed but may face efficiency challenges.

- **Compilation Commands:**
  - **C++:**  
    ```bash
    g++ -std=c++11 -O3 -Wall file.cpp -lm
    ```
  - **C:**  
    ```bash
    gcc -O3 -ansi -Wall file.c -lm
    ```

- **Algorithmic Approach:**
  - **Tree Validation:**
    - Construct the graph using appropriate data structures (e.g., adjacency lists) to represent the parent-child relationships.
    - Verify that each node has at most two parents.
    - Check for cycles or inconsistencies that would invalidate the genealogical tree structure.
  
  - **Computing Nearest Common Ancestors:**
    - For each of the given nodes `v1` and `v2`, traverse the graph upwards (using DFS or BFS) to compile the set of all ancestors.
    - Determine the intersection of these two sets to identify common ancestors.
    - For each common ancestor, ensure it is a nearest common ancestor by checking that none of its descendants (that are also common ancestors) exist.
  
  - **Edge Cases:**
    - Handle cases where the graph is invalid.
    - Manage scenarios where there are no common ancestors or where multiple NCAs exist.

- **Code Structure:**
  - **Input Parsing:**  
    Read the input from standard input, parsing node identifiers, graph dimensions, and the parent-child relations.
  - **Graph Construction:**  
    Build the graph using an efficient representation to facilitate quick ancestor lookups and traversals.
  - **Validation & Processing:**  
    Implement functions for:
    - Validating the genealogical tree structure.
    - Traversing the graph to collect ancestor data.
    - Identifying the nearest common ancestors.
  - **Output Generation:**  
    Write the results to standard output, ensuring that the NCAs (if any) are printed in ascending order with the correct formatting.

## Performance Considerations

- The implementation emphasizes efficiency:
  - **Graph Traversal:**  
    Use efficient traversal techniques (DFS/BFS) to compute the ancestor sets.
  - **Memory and Time Optimization:**  
    Cache intermediate results to avoid redundant computations and ensure the solution operates within the strict resource constraints typical of automated testing environments.
