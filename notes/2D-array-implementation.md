# 2D Arrays and Memory Representation in C++

## 1. Introduction to 2D Arrays in C++

A 2D array in C++ (often called a "matrix") is essentially an array of arrays. It's declared using two subscript operators: `arrayName[rows][columns]`.

* **Declaration:** `int A[3][4];` declares an array named `A` with 3 rows and 4 columns, totaling 12 elements.
* **Contiguous Memory:** Despite the logical two-dimensional structure, the operating system (OS) stores all array elements in a **single, contiguous block of memory**.
    * **Contiguous memory** means that if one element is at address $X$, the next element is at $X + \text{size of data type}$ bytes.

### 1.1 Logical vs. Physical View

| View | Description |
| :--- | :--- |
| **Logical View** | The conceptual structure of rows and columns, allowing access via two indices (e.g., `A[i][j]`). |
| **Physical View** | The actual linear arrangement of elements in the computer's RAM. |

The two major methods for mapping the logical view to the physical view are Row-Major and Column-Major ordering.

---

## 2. Row-Major Ordering (RMO)

Row-Major Ordering is the standard and default implementation for multi-dimensional arrays in C and C++. In this scheme, elements of a single **row** are stored consecutively in memory.

### 2.1 Implementation

The entire first row is stored, followed by the entire second row, and so on.

#### Row-Major Memory Layout

For an array $A[3][4]$ (3 rows, 4 columns):

```

\+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
| R0C0| R0C1| R0C2| R0C3| R1C0| R1C1| R1C2| R1C3| R2C0| R2C1| R2C2| R2C3|
\+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
^                                 ^                                 ^
|                                 |                                 |
B (Base Address)                  B + (4*size)                      B + (8*size)

```
* $R_iC_j$ represents the element at Row $i$ and Column $j$.

### 2.2 Address Calculation Formula

The formula calculates the physical address of the element $A[i][j]$ given its logical indices.

Let:
* $B$ = Base Address (Address of the first element, $A[0][0]$).
* $i$ = Row index (starts from 0 for C++).
* $j$ = Column index (starts from 0 for C++).
* $m$ = Total number of rows.
* $n$ = Total number of columns.
* $size$ = Size of one element (e.g., 4 bytes for `int`).

#### C/C++ (0-based indexing):
$$ \text{Address}(A[i][j]) = B + [(i \times n) + j] \times \text{size} $$

* $(i \times n)$: Skips the $i$ complete rows before the target row.
* $+ j$: Skips the $j$ elements within the current row $i$ to reach column $j$.

#### Standard Formula (1-based indexing):
If the array indices start at 1 (i.e., $1 \le i \le m$ and $1 \le j \le n$), the formula becomes:
$$ \text{Address}(A[i][j]) = B + [((i-1) \times n) + (j-1)] \times \text{size} $$

---

## 3. Column-Major Ordering (CMO)

Column-Major Ordering is the default scheme used in languages like FORTRAN and MATLAB. In this scheme, elements of a single column are stored consecutively in memory.

### 3.1 Implementation

The entire first column is stored, followed by the entire second column, and so on.

#### Column-Major Memory Layout

For an array $A[3][4]$ (3 rows, 4 columns):

```

\+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
| R0C0| R1C0| R2C0| R0C1| R1C1| R2C1| R0C2| R1C2| R2C2| R0C3| R1C3| R2C3|
\+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
^           ^           ^
|           |           |
B           B + (3*size)  B + (6*size)

````
* $R_iC_j$ represents the element at Row $i$ and Column $j$.

### 3.2 Address Calculation Formula

The formula calculates the physical address of the element $A[i][j]$ using CMO.

Let:
* $B$ = Base Address (Address of the first element, $A[0][0]$).
* $i$ = Row index (starts from 0 for C++).
* $j$ = Column index (starts from 0 for C++).
* $m$ = Total number of rows.
* $n$ = Total number of columns.
* $size$ = Size of one element.

#### C/C++ (0-based indexing):
$$ \text{Address}(A[i][j]) = B + [(j \times m) + i] \times \text{size} $$

* $(j \times m)$: Skips the $j$ complete columns before the target column.
* $+ i$: Skips the $i$ elements within the current column $j$ to reach row $i$.

#### Standard Formula (1-based indexing):
If the array indices start at 1 (i.e., $1 \le i \le m$ and $1 \le j \le n$), the formula becomes:
$$ \text{Address}(A[i][j]) = B + [((j-1) \times m) + (i-1)] \times \text{size} $$

---

## 4. Advanced: 2D Arrays and Pointers in C++

In C++, 2D arrays are handled using pointers and are often implemented in three main ways:

### 4.1 1. Statically Allocated Array

The array size is fixed at compile time and allocated on the **Stack**. This is the contiguous memory layout described in sections 2 and 3.

```cpp
int A[3][4]; // A is a 2D array of 3 integer arrays, each with 4 elements.
````

### 4.2 2. Array of Pointers

A 1D array of pointers is created, and each pointer points to a separate 1D array of integers. This is typically used for **jagged arrays** (where rows have different sizes) and is partially contiguous (only the pointer array is contiguous).

#### Array of Pointers

```
+----+----+----+     Memory (Heap)
| *P0| *P1| *P2|  --► +----+----+----+----+ (Row 0)
+----+----+----+  --► +----+----+----+ (Row 1)
   ^              --► +----+----+----+----+----+ (Row 2)
   |
   P (Pointer Array on Stack or Heap)
```

```cpp
int **P;
P = new int*[3]; // Pointers are contiguous
P[0] = new int[4]; // Row 0 is contiguous
P[1] = new int[3]; // Row 1 (Jagged/non-standard)
// ...
```

### 4.3 3. Array of `std::vector` (Modern C++)

Using the `std::vector` container is the modern C++ approach. It abstracts away manual memory management and is safer.

```cpp
#include <vector>
// A vector of vectors (dynamically sized 2D array)
std::vector<std::vector<int>> matrix;
```

This is generally implemented as an array of pointers to dynamically allocated memory, similar to method 2, but managed automatically.

