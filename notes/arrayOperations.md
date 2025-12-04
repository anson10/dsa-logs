# Array Operations

This document explains the fundamentals of arrays, including how they are stored in memory, how elements are accessed, and how operations such as traversal, insertion, and deletion work.

Code implementations for these operations are available at:  
[dsa-logs/code/arrays](https://github.com/anson10/dsa-logs/tree/main/code/arrays)
---

# Array Basics

## What is an Array?

An array is a collection of elements of the same data type stored in contiguous memory locations.

Properties:
- Fixed size  
- Elements must be of the same type  
- Stored in continuous memory  

---

## Array Declaration and Memory Allocation

Example in C++:

```cpp
int myArray[5];
````

If each `int` is 4 bytes and the array starts at address `1000`, the memory layout looks like:

| Index | Value | Address (Hex) | Address (Decimal) |
| ----: | ----: | :-----------: | ----------------: |
|     0 |    10 |     0x1000    |              1000 |
|     1 |    20 |     0x1004    |              1004 |
|     2 |    30 |     0x1008    |              1008 |
|     3 |    40 |     0x100C    |              1012 |
|     4 |    50 |     0x1010    |              1016 |

### ASCII Representation

```
+-------+-------+-------+-------+-------+
|  10   |  20   |  30   |  40   |  50   |
+-------+-------+-------+-------+-------+
| [0]   | [1]   | [2]   | [3]   | [4]   |
+-------+-------+-------+-------+-------+
 1000    1004    1008    1012    1016
```

---

# Array Access

Arrays use zero-based indexing.

### Address Calculation

```
Address(A[i]) = Base Address + i × Size of Data Type
```

Example:

```cpp
int value = myArray[2]; // Accesses the element at index 2
```

Since arrays are contiguous, this calculation works in constant time.
Therefore, array access has O(1) time complexity.

---

# Array Operations

## 1. Traversal

Traversal means visiting each element exactly once.

Example:

| Index | Value | Action |
| ----: | ----: | ------ |
|     0 |    10 | Visit  |
|     1 |    20 | Visit  |
|     2 |    30 | Visit  |
|     3 |    40 | Visit  |
|     4 |    50 | Visit  |

Typical loop:

```cpp
for (int i = 0; i < size; i++) {
    // process a[i]
}
```

Time complexity: O(n)

---

## 2. Insertion

Insertion into an array requires shifting elements to maintain contiguous memory.

### Why shift?

Arrays cannot grow in the middle.
To insert at position `pos`, we must free that index by shifting elements from the end backwards.

### Logic Explanation

Given:

* `a[]` = array
* `size` = current number of elements
* `num` = element to insert
* `pos` = 1-based target position

Steps:

1. Start from the last element and shift each element one index to the right.
2. Stop once position `pos-1` becomes free.
3. Insert `num` at index `pos-1`.
4. Increase `size`.

### Example Code Logic

```cpp
for (int i = size - 1; i >= pos - 1; i--) {
    a[i + 1] = a[i];
}
a[pos - 1] = num;
size++;
```

Reason for backward loop:
Shifting forward would overwrite values before they are moved.

Time complexity:

* Best case (insert at end): O(1)
* Worst case (insert at beginning): O(n)

---

## 3. Deletion

Deletion removes an element at a given position and shifts elements left to fill the gap.

### Why shift?

Arrays must remain contiguous, so after deleting an element, all elements on the right shift left by one.

### Logic Explanation

Given:

* delete element at position `pos` (1-based)

Steps:

1. Start from index `pos`.
2. Shift each element left by one: `a[i - 1] = a[i]`.
3. Reduce size.

### Code Logic

```cpp
for (int i = pos; i < size; i++) {
    a[i - 1] = a[i];
}
size--;
```

Time complexity: O(n)

---

# Summary

| Operation | Time Complexity | Notes                      |
| --------- | --------------- | -------------------------- |
| Access    | O(1)            | Direct address calculation |
| Traversal | O(n)            | Visit all elements         |
| Insertion | O(n)            | Requires shifting          |
| Deletion  | O(n)            | Requires shifting          |

Full code is provided here:
[https://github.com/anson10/dsa-logs/tree/main/code/arrays](https://github.com/anson10/dsa-logs/tree/main/code/arrays)
