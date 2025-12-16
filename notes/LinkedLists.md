# Singly Linked Lists

## 1. What a Linked List Actually Represents 
Code implementations for these operation are available at:  
[dsa-logs/code/arrays/linkedListsImplementation](https://github.com/anson10/dsa-logs/blob/main/code/arrays/linkedListsImplementation.cpp)

A linked list is a linear data structure where elements are not stored contiguously in memory.

Instead, the list is composed of nodes, and each node contains:
1. **Data** – the actual value
2. **Link (pointer)** – the address of the next node

It consists of:
- Individually allocated nodes
- One external pointer called `HEAD`
- Each node stores a pointer to exactly one next node

### Conceptual Model

Think of the list as a directed chain of memory blocks:

```

HEAD → N1 → N2 → N3 → NULL

```

This is NOT:
- An array
- A container with indices
- A collection with ownership tracking

It is simply:
> A starting pointer (`HEAD`) and a sequence of `next` pointers

---

## 2. The Single Most Important Invariant

At all times, a valid linked list must satisfy:

> Every node in the list must be reachable from `HEAD` by following `next` pointers.

This invariant governs every operation.

If violated:
- Nodes are lost
- Memory leaks occur
- Logical corruption happens

---

## 3. Why `HEAD` Is Special (Logic, Not Syntax)

`HEAD` is the only external entry point into the list.

Nothing else points to the list.

```

(no reference)   A → B → C

```

This is not a list, because nothing points to `A`.

Therefore:
- Changing `HEAD` changes the entire list
- Losing `HEAD` loses the entire structure

---

## 4. What `next` Logically Means

Each node’s `next` pointer answers exactly one question:

> “What is the next node in the sequence?”

It does NOT mean:
- Ownership
- Parent-child
- Index relationship

It simply defines **order**.

```

A.next = B   means   A comes before B

```

---

## 5. Traversal — The Fundamental Operation

### Why Traversal Exists

You cannot:
- Jump to index `i`
- Ask for “previous node”
- Skip nodes arbitrarily

Because:
> The only information available is `current → next`

Traversal is the act of **discovering structure at runtime**.

---

## 6. Length Finding 
Code implementations for these operations are available at:  
[dsa-logs/code/arrays/linkedListsLength](https://github.com/anson10/dsa-logs/blob/main/code/arrays/linkedListsLength.cpp)
### What Does “Length” Mean?

Length is:
> The count of nodes reachable from `HEAD` before reaching `NULL`

Important:
- Length is **not stored**
- Length is **derived**

---

### Why Length Cannot Be Known Without Traversal

Consider:

```

HEAD → ? → ? → ? → NULL

```

There is no metadata saying:
- How many nodes exist
- Where the list ends

Therefore:
> The only way to know length is to follow pointers until termination

---

### Logical Invariant During Length Calculation

At each step:
- Current node is reachable
- Next node may or may not exist
- Count increases by exactly one

Once `NULL` is reached:
- Structure ends
- Count is complete

---

## 7. Insertion 
Code implementations for these operations are available at:  
[code/arrays/linkedListInsertionandDeletion.cpp/](https://github.com/anson10/dsa-logs/blob/main/code/arrays/linkedListInsertionandDeletion.cpp)

Insertion is not about adding data.

Insertion is about:
> Introducing a new node without breaking reachability of existing nodes

This leads to two rules:

### Insertion Rules

1. No existing node may become unreachable
2. All pointer changes must preserve the chain

Every insertion algorithm is just a strategy to satisfy these rules.

---

## 8. Insertion at the Beginning —Logic Breakdown

### Initial State

```

HEAD → A → B → C

```

### Desired Final State

```

HEAD → X → A → B → C

```

---

### Logical Constraints

- `A` must remain reachable
- `X` must become the first reachable node
- No traversal is allowed (we already know where the beginning is)

---

### Logical Steps (Why This Order Exists)

1. `X` must point to what `HEAD` currently points to  
   Why?  
   Because `A` is the entire existing list.

2. `HEAD` must be updated to `X`  
   Why?  
   Because `HEAD` defines entry.

---

### Why Reversing These Steps Breaks the List

If you update `HEAD` first:

```

HEAD → X
A → B → C   (lost forever)

```

Invariant broken:
> Existing nodes are no longer reachable from `HEAD`

---

## 9. Insertion at the End — Logic Breakdown

### Problem Definition

We want:
```

A → B → C → X → NULL

```

But:
- We don’t know where `C` is
- Only `NULL` tells us the end

---

### Why Traversal Is Mandatory

Only one condition defines the last node:

```

last.next == NULL

```

There is no shortcut.

---

### Logical Steps

1. Traverse until a node whose `next` is `NULL`
2. Attach new node by changing exactly **one pointer**
3. Ensure new node terminates with `NULL`

---

### Why Only One Pointer Is Modified

Before:
```

C.next = NULL

```

After:
```

C.next = X
X.next = NULL

```

No other node is affected.
Invariant preserved.

---

## 10. Insertion at Any Position — The Key Insight

### Fundamental Rule

To insert at position `i`:
> You must modify the `next` pointer of node at position `i-1`

Never the node at `i`.

---

### Why This Is True

Given:
```

A → B → C → D

```

Insert `X` at index `2`:

```

A → B → X → C → D

```

Observe:
- `C` still exists
- `B` is the last node before insertion point

---

### Logical Pointer Rewiring

To preserve reachability:

1. New node must point to what `B` was pointing to
2. `B` must now point to new node

---

### Why Order Matters (Critical)

Wrong order:
```

B.next = X
X.next = ???   (C is already lost)

```

Correct order:
```

X.next = C
B.next = X

```

This preserves both halves of the list.

---

## 11. Deletion — Logical Meaning

Deletion does NOT mean destroying memory.

Deletion means:
> Making a node unreachable from `HEAD`

Memory deallocation is secondary.

---

## 12. Deletion at the Beginning — Logic

### Initial State

```

HEAD → A → B → C

```

### Desired State

```

HEAD → B → C

```

---

### Logical Step

- Change `HEAD` to point to `A.next`

Why this works:
- `A` becomes unreachable
- `B` remains reachable
- No traversal needed

---

## 13. Deletion at the End — Logic

### Problem

We cannot directly access the second-last node.

---

### Why Second-Last Node Matters

To remove `C`:

```

A → B → C → NULL

```

We must change:
```

B.next = NULL

```

But we don’t know where `B` is without traversal.

---

### Logical Requirement

Find node such that:
```

current.next.next == NULL

```

That node is the second-last.

---

## 14. Deletion at Any Position 

### Key Rule

To delete node at index `i`:
> Modify the `next` pointer of node at index `i-1`

---

### Why This Works

Given:
```

A → B → C → D

```

Delete `C`:

```

B.next = C.next

```

Result:
```

A → B → D

```

`C` becomes unreachable.
Invariant preserved.

---

## 15. Reversal 
Code implementations for these operations are available at:  
[code/arrays/linkedListsReversal.cpp](https://github.com/anson10/dsa-logs/blob/main/code/arrays/linkedListsReversal.cpp)
### What Reversal Really Is

Reversal means:
> Every `next` pointer must be inverted

Original:
```

A → B → C → NULL

```

Reversed:
```

C → B → A → NULL

```

---

## 16. Why Reversal Is Non-Trivial

Problems:
- Pointers only go forward
- Once reversed, access to remaining nodes is lost
- You must preserve reachability at every step

---

## 17. Reversal Logic — Three Regions Model

At any moment, the list is split into:

```

REVERSED ← CURRENT → UNREVERSED

```

Initial:
```

NULL ← A → B → C

```

---

### Step-by-Step Logic

#### Step 1
Redirect `A.next` to `NULL`

```

NULL ← A   B → C

```

Invariant:
- Reversed part is reachable
- Unreversed part is reachable

---

#### Step 2
Redirect `B.next` to `A`

```

NULL ← A ← B   C

```

---

#### Step 3
Redirect `C.next` to `B`

```

NULL ← A ← B ← C

```

Now:
```

HEAD → C

```

---

## 18. Why Temporary Storage Is Mandatory

Before changing a pointer:
- You must remember where the unreversed part starts

Otherwise:
- Remaining nodes become unreachable
- Invariant breaks

---

