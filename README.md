# Algorithm Projects Summary

This repository contains implementations for two algorithmic projects developed as part of the Analysis and Synthesis of Algorithms course. Both projects focus on efficient graph and sequence processing techniques using optimal data structures and algorithms.

## Project 1: Longest Increasing Subsequence Analysis

- **Objective:**  
  Process a sequence of integers to determine the longest strictly increasing subsequence and count how many such maximum-length subsequences exist.

- **Implementation Highlights:**  
  - **Input/Output:**  
    Reads a single integer to select the problem type followed by the sequence(s) of integers.  
    Outputs the length of the longest increasing subsequence and the number of such subsequences for a single sequence input, or the length of the longest common strictly increasing subsequence for two sequences.
  - **Algorithm:**  
    Uses dynamic programming and efficient traversal to identify and count valid subsequences.
  - **Language & Compilation:**  
    Preferably implemented in C or C++ with provided compilation flags for optimal performance.

## Project 2: Genealogical Tree Analysis

- **Objective:**  
  Validate a directed graph as a proper genealogical tree and compute the nearest common ancestors (NCAs) for two specified nodes.

- **Implementation Highlights:**  
  - **Input/Output:**  
    Reads two node identifiers, the number of vertices and edges, and a list of parent-child relations.  
    Outputs the NCAs in ascending order if the tree is valid, or specific error codes if the structure is invalid.
  - **Algorithm:**  
    - **Tree Validation:** Checks for valid tree structure by ensuring each node has at most two parents and that no cycles exist.
    - **NCA Computation:** Uses graph traversal (DFS/BFS) to collect ancestors and determine the nearest common ancestors by intersecting ancestor sets and filtering out non-minimal common ancestors.
  - **Language & Compilation:**  
    Preferably implemented in C or C++ with strict performance constraints in mind.
