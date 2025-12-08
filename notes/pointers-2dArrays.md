## 1. Pointers and 2D Arrays

**Code implementations for these operations are available at:  
[dsa-logs/code/arrays](https://github.com/anson10/dsa-logs/tree/main/code/arrays)**
---

In C++, a 2D array, such as `int A[R][C]`, is fundamentally treated as a **1D array of 1D arrays** (rows).

1.  **Array Name (`A`):** The name of the 2D array, `A`, acts as a **constant pointer to the first row** (i.e., a pointer to an array of $C$ integers). Its data type is often conceptualized as `int (*)[C]`.
2.  **Row Element (`A[i]`):** When the row index $i$ is used, `A[i]` acts as a **constant pointer to the first element of that row** (i.e., the address of `A[i][0]`). Its data type is `int *`.

The key is that pointer arithmetic scales appropriately:

* **`A + i`:** Moves past $i$ complete rows. Since each row is an array of $C$ integers, this moves $i \times (\text{size of row})$ bytes.
* **`*(A + i)`:** Dereferences the row pointer to get the row itself, which immediately **decays** into a pointer to its first element, $\&A[i][0]$.

---

## 2. Example Array and Memory Representation

Let's use the provided 2D array for demonstration.

**Declaration:**
```cpp
int a[3][3] = {
    {2, 4, 6}, // Row 0
    {1, 3, 5}, // Row 1
    {0, 1, 3}  // Row 2
};
````

Assume the **Base Address (B)** is `1000` and `sizeof(int)` is 4 bytes.

### ASCII Art: Row-Major Memory Implementation

The 2D array is stored contiguously in Row-Major Order (Row 0, then Row 1, then Row 2).

```
+-------+-------+-------+ | +-------+-------+-------+ | +-------+-------+-------+
|a[0][0]|a[0][1]|a[0][2]| |a[1][0]|a[1][1]|a[1][2]|   |a[2][0]|a[2][1]|a[2][2]|
|   2   |   4   |   6   | |   1   |   3   |   5   |   |   0   |   1   |   3   |
+-------+-------+-------+ | +-------+-------+-------+ | +-------+-------+-------+
  1000    1004    1008       1012    1016     1020          1024    1028    1032  <-- Addresses (4 byte increments)
  ▲                       ▲                       ▲
  |                       |                       |
  a (1000)                a + 1 (1012)            a + 2 (1024)
  a[0] (1000)             a[1] (1012)             a[2] (1024)
```

-----

## 3\. Referencing and Dereferencing Examples
The core idea is to find the address of the element first, then dereference it to get the value.

### 3.1 Accessing the Element $A[i][j]$

All the following expressions are equivalent ways to access the **value** of the element at Row $i$ and Column $j$.

| Expression | Interpretation | Value (for $i=1, j=2$ which is `a[1][2]=5$) |
| :--- | :--- | :--- |
| **Standard Array** | Standard notation. | **5** |
| `a[1][2]` | | |
| **Pointer Notation 1** | Get the address of row $i$, dereference it to get the row pointer, then do 1D pointer arithmetic. | **5** |
| `*(*(a + i) + j)` | `*(*(a + 1) + 2)` | |
| **Pointer Notation 2** | Get the pointer to the element $a[i][j]$ using $a[i]$ (which is $\&a[i][0]$). | **5** |
| `*(a[i] + j)` | `*(a[1] + 2)` | |
| **Mixed Notation** | Find the address of $a[i][j]$, then dereference it. | **5** |
| `*( (a+i)[j] )` | Dereferences the $j$-th element in the $i$-th row block. | |

### 3.2 Accessing the Address of the Element $\&A[i][j]$

All the following expressions are equivalent ways to access the **address** of the element at Row $i$ and Column $j$.

| Expression | Interpretation | Address (for $i=1, j=2$ which is `a[1][2]`, Address: 1020) |
| :--- | :--- | :--- |
| **Standard Array** | Standard Address-of operator. | **1020** |
| `&a[1][2]` | | |
| **Pointer Notation 1** | Get the address of row $i$, dereference it to get the row pointer, then apply 1D pointer arithmetic. | **1020** |
| `*(a + i) + j` | `*(a + 1) + 2` | |
| **Pointer Notation 2** | Get the row pointer $a[i]$ ($\&a[i][0]$), and use 1D pointer arithmetic. | **1020** |
| `a[i] + j` | `a[1] + 2` | |

### 3.3 Accessing the Entire Row Pointer (Address of Row $i$)

| Expression | Interpretation | Address (for Row 2, $i=2$, Address: 1024) |
| :--- | :--- | :--- |
| **Row Pointer** | Row name decays to a pointer to its first element. | **1024** |
| `a[2]` | | |
| **Pointer Arithmetic** | Array name (`a`) + row offset (2). | **1024** |
| `a + 2` | | |
| **Row Address-of** | Get the address of the entire row (type is pointer to array). | **1024** |
| `&a[2]` | | |

-----
