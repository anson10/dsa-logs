# 💻 Pointers and Arrays in C++
## 1. Understanding Pointers

A **pointer** is a variable whose value is the **memory address** of another variable. It "points" to the location in memory where the actual data is stored.

### 1.1 Key Operators

| Operator | Name | Purpose | Example |
| :---: | :---: | :--- | :--- |
| **`*`** | **Dereference** / **Value-at-Address** | Accesses the **value** stored at the memory address the pointer holds. | `cout << *p;` |
| **`&`** | **Address-of** | Returns the **memory address** of a variable. | `p = &var;` |
| **`*`** | **Declaration** | Used to declare a pointer variable. | `int *p;` |

### 1.2 Pointer Declaration and Usage

```cpp
int number = 10;
int *p;       // Declaration: p is a pointer to an integer

p = &number;  // Assignment: p now stores the memory address of 'number'
````

### 1.3 The Pointer Concept

Imagine memory as a set of labeled boxes (addresses).

```
+-----------+    +-------------+
| variable  |    |   pointer   |
| (number)  |    |     (p)     |
+-----------+    +-------------+
| Value: 10 |    | Address of  |
|           | --►|   'number'  |
+-----------+    +-------------+
| Address:  |    | Address:    |
| 0x100     |    | 0x200       |
+-----------+    +-------------+
```

  * `p` stores `0x100`.
  * `*p` evaluates to **10**.
  * `&p` evaluates to **0x200**.

-----

## 🔗 2. Pointers and Arrays

In C++, there is a powerful and essential relationship between arrays and pointers.

### 2.1 Array Name as a Constant Pointer

In most contexts, the **name of an array** (`arr`) acts as a **constant pointer** to the address of its **first element** (`&arr[0]`).

```cpp
int arr[5] = {10, 20, 30, 40, 50};

// The following expressions are EQUIVALENT:
cout << arr;       // Prints the address of the first element (e.g., 0x400)
cout << &arr[0];   // Prints the address of the first element (e.g., 0x400)
```

### 2.2 Array Element Access

Because the array name acts as a pointer, you can use **Pointer Arithmetic** to access elements.

| Operation | Array Notation | Pointer Notation | Result |
| :--- | :---: | :---: | :--- |
| **Address of element** | `&arr[i]` | `(arr + i)` | Address of the i-th element. |
| **Value of element** | `arr[i]` | `*(arr + i)` | Value of the i-th element. |

### Array and Pointer

This demonstrates how pointer arithmetic works. Since `int` is typically 4 bytes, adding 1 to the pointer moves the address by 4 bytes.

```
Array: arr
+-----+-----+-----+-----+-----+
| 10  | 20  | 30  | 40  | 50  | (Values)
+-----+-----+-----+-----+-----+
| 0x400|0x404|0x408|0x40C|0x410| (Addresses)
+-----+-----+-----+-----+-----+
  ▲
  |
  +-- arr (constant pointer to 0x400)
  +-- p   (variable pointer to 0x400)
```

  * `arr` is `0x400`.
  * `arr + 2` is `0x408`.
  * `*(arr + 2)` is **30**.

-----

## 3. Operations on Pointers and Arrays

The versatility of pointers comes from the operations you can perform on them.

### 3.1 Pointer Arithmetic

Pointer arithmetic is the ability to perform mathematical operations on a pointer's address.

| Operation | Description | Example (Assuming `int *p = arr;`) |
| :--- | :--- | :--- |
| **Increment** | Moves the pointer to the **next memory location** (next element). | `p++;`  // Now points to `arr[1]` |
| **Decrement** | Moves the pointer to the **previous memory location** (previous element). | `p--;`  // Moves back to `arr[0]` |
| **Addition/Subtraction** | Skips $N$ elements forward or backward. | `p = p + 3;` // Points to `arr[3]` |
| **Subtraction** | Subtracting two pointers of the **same type** yields the number of elements between them. | `long diff = p2 - p1;` |

> **NOTE:** You **cannot** use addition, multiplication, or division with two pointers.


