# DSA

C++ implementations of data structures and sorting algorithms, organized as learning exercises in memory management, templates, composition, and algorithm design.

## Contents

- Dynamic arrays, singly linked lists, and circular doubly linked lists.
- Stacks, queues, binary search trees, and a student-record hashmap.
- Binary and indexed priority queues.
- Recursive/iterative merge sort and quicksort demonstrations.

Each topic has source files and a small example. There is no unified build system.

## Run an example

With a C++17 compiler, from the repository root:

```sh
g++ -std=c++17 Merge_Sort/iterativeMergeSort.cpp -o merge-sort
./merge-sort
```

The example prints an array before and after sorting. On Windows, run the generated `merge-sort.exe`.

## Status

Work in progress. BST, Queue, and Stack contain machine-specific include paths and incompatible interfaces. Some list, hashmap, indexed-heap, and recursive-sort operations are incorrect. The demonstrations are not a correctness test suite; compile from source rather than using the checked-in binaries.
