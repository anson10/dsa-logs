
# Circular Linked List (Tail-Pointer Implementation)

**Code implementations for these operations are available at:  
[dsa-logs/code/arrays](https://github.com/anson10/dsa-logs/blob/main/code/arrays/circularLinkedListDeletion.cpp)**


A Circular Linked List (CLL) is a linear data structure where the last node points back to the first node, forming a loop. By maintaining only a Tail pointer, we gain efficient access to both the beginning and the end of the list.

##  The Tail Pointer

In a standard linked list, you usually keep a `head`. In a circular list, the `tail` is more powerful because:

* **The Tail** is where the pointer sits.
* **The Head** is always `tail->next`.

```text
      [Head]          [Node]          [Tail]
      +---+           +---+           +---+
  +-->| 1 | --next--> | 2 | --next--> | 3 | --+
  |   +---+           +---+           +---+   |
  +------------------- next ------------------+

```

---

##  Operations Logic

### 1. Deletion from the Beginning

**Goal:** Remove the first element (the one immediately after the tail).

* **Conceptual Steps:**
1. Identify the **Head** (it’s the node the Tail points to).
2. Change the **Tail's next** pointer to skip the Head and point to the second node.
3. Remove the old Head node.


* **Complexity:**  (Instant)

**ASCII Visualization:**

```text
BEFORE: [Tail] -> [A] -> [B] -> [C] -> (back to A)
ACTION: Tail points to [B] instead of [A].
AFTER:  [Tail] -> [B] -> [C] -> (back to B)

```

---

### 2. Deletion from the End

**Goal:** Remove the last element (the Tail itself).

* **Conceptual Steps:**
1. Since we can't look "backward," we start at the Head and walk through the circle.
2. Stop at the node **right before** the Tail.
3. Update this node's `next` to point to the Head.
4. Move the "Tail" label to this current node.
5. Delete the old Tail.


* **Complexity:**  (Requires traversal)

**ASCII Visualization:**

```text
BEFORE: [A] -> [B] -> [C(Tail)] -> (back to A)
ACTION: Find [B], make [B] point to [A].
AFTER:  [A] -> [B(Tail)] -> (back to A)

```

---

### 3. Deletion at a Specific Position

**Goal:** Remove a node at index `i`.

* **Conceptual Steps:**
1. Walk through the list until you reach the node at `position - 1`.
2. Tell this node to "reach over" the target node and grab the address of the node that follows it.
3. **Edge Case:** If the node being removed was the Tail, move the Tail pointer to the previous node.


* **Complexity:**  (Searching takes time)

**ASCII Visualization:**

```text
BEFORE: [A] -> [B] -> [C] -> [D]
ACTION: Node [A] now points to [C]. [B] is disconnected.
AFTER:  [A] ---------> [C] -> [D]

```

---

##  Performance Summary

| Operation | Complexity | Efficiency Note |
| --- | --- | --- |
| **Delete Start** |  | Best-in-class; no searching required. |
| **Delete End** |  | Slowest; must walk the circle to find the "pre-tail" node. |
| **Insertion** |  | Inserting at both ends is instant with a Tail pointer. |
| **Search** |  | Must check nodes one by one. |

---

##  Why use a Tail-only CLL?

1. **Memory Saving:** You only manage one pointer variable (`tail`) instead of two (`head` and `tail`).
2. **Buffer Management:** Perfect for "Round Robin" scheduling or streaming buffers where you constantly add to the end and remove from the front.

