# Doubly Linked List – Insertion Operations 

**Code implementations for these operations are available at:  
[dsa-logs/code/arrays](https://github.com/anson10/dsa-logs/blob/main/code/arrays/doublyLinkedListInsertion.cpp)**

---

## 1. What is a Doubly Linked List?

A Doubly Linked List (DLL) is a sequence of nodes where:

- Each node knows:
  - who comes before it
  - who comes after it

### Structure of one node (conceptually)

```

+---------------------------+
|  prev  |  data  |  next   |
+---------------------------+

```

- `prev` → address of previous node
- `data` → actual value
- `next` → address of next node

---

## 2. Global View of the List

The program maintains **two global pointers**:

- `head` → points to the first node
- `tail` → points to the last node

### Empty list state

```

head → NULL
tail → NULL

```

---

## 3. Creating the Initial List (`create` logic)

### Goal
Create a list by continuously adding nodes at the end.

### Logical steps

1. Ask user for data
2. Create a new node
3. If list is empty:
   - new node becomes both `head` and `tail`
4. Else:
   - attach new node after `tail`
   - move `tail` forward

### ASCII progression

#### First node

```

head, tail
|
v
NULL ← [10] → NULL

```

#### Second node

```

head                tail
|                   |
v                   v
NULL ← [10] ↔ [20] → NULL

```

#### Third node

```

head                         tail
|                            |
v                            v
NULL ← [10] ↔ [20] ↔ [30] → NULL

```

---

## 4. Insertion at the Beginning

### Goal
Insert a new node before the current head

### Logical steps

1. Create a new node
2. Set:
   - `newnode.prev = NULL`
   - `newnode.next = head`
3. If list was empty:
   - `head = tail = newnode`
4. Else:
   - link old head back to new node
   - move `head` to new node

### ASCII example

#### Before insertion

```

head                tail
|                   |
v                   v
NULL ← [10] ↔ [20] → NULL

```

#### Insert `5` at beginning

```

head                     tail
|                        |
v                        v
NULL ← [5] ↔ [10] ↔ [20] → NULL

```

Key idea:  
**Only pointers change — no shifting of data**

---

## 5. Insertion at the End

### Goal
Insert a new node **after the current tail**

### Logical steps

1. Create a new node
2. Set:
   - `newnode.next = NULL`
3. If list is empty:
   - `head = tail = newnode`
4. Else:
   - connect old tail to new node
   - move `tail` forward

### ASCII example

#### Before insertion

```

head                tail
|                   |
v                   v
NULL ← [10] ↔ [20] → NULL

```

#### Insert `30` at end

```

head                         tail
|                            |
v                            v
NULL ← [10] ↔ [20] ↔ [30] → NULL

```

Why this is efficient:
- Because `tail` exists, insertion is **O(1)**

---

## 6. Insertion at a Specific Position

### Goal
Insert a node at index `pos` (0-based)

### High-level logic

1. If `pos == 0`:
   - same as insertion at beginning
2. Otherwise:
   - traverse to node at `pos - 1`
   - insert new node between two nodes

---

### Pointer logic (MOST IMPORTANT SECTION)

Assume we want to insert `15` at position `1`

#### Initial list

```

Index:   0      1
↓      ↓
NULL ← [10] ↔ [20] → NULL

```

We stop at node `10` (position `pos - 1`)

---

### Step-by-step pointer rewiring

#### Step 1: New node points forward

```

newnode.next = temp.next

```
```

[15] → [20]

```

---

#### Step 2: New node points backward

```

newnode.prev = temp

```
```

[10] ← [15]

```

---

#### Step 3: Next node points back to new node

```

temp.next.prev = newnode

```
```

[15] ← [20]

```

---

#### Step 4: Temp points forward to new node

```

temp.next = newnode

```

---

### Final structure

```

NULL ← [10] ↔ [15] ↔ [20] → NULL

```

 **Key insight**:  
Insertion is done by **rewiring 4 pointers**, not by moving data.

---

## 8. Display Logic

### Goal
Traverse the list from `head` to `tail` and print data

### Logical steps

1. Start from `head`
2. Print data
3. Move to `next`
4. Stop when `NULL` is reached

### ASCII traversal

```

ptr → [10] → [15] → [20] → NULL

```

Output:
```

10 <-> 15 <-> 20 <-> NULL

```

---

## 8. Why `head` and `tail` both matter

| Pointer | Purpose |
|------|--------|
| `head` | Start traversal, insert at beginning |
| `tail` | Insert at end in O(1) time |

Without `tail`, insertion at end would require full traversal.

---

## 9. Mental Model (VERY IMPORTANT)

### Think of the list as:

- Nodes are **boxes in memory**
- Pointers are **arrows**
- Operations only **change arrows**

Nothing is shifted.
Nothing is copied.
Only addresses change.

---

## 10. One-line summary of each operation

- **Create** → keep attaching nodes at the end
- **Insert Beginning** → new node becomes head
- **Insert End** → new node becomes tail
- **Insert Position** → reconnect 4 pointers
- **Display** → walk using `next`

---

