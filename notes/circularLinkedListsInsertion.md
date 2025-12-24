
# Circular Linked List: Insertion Logic


**Code implementations for these operations are available at:  
[dsa-logs/code/arrays](https://github.com/anson10/dsa-logs/blob/main/code/arrays/circularLinkedListInsertions.cpp)**



In a Circular Linked List (CLL), the last node (tail) doesn't point to `NULL`; it points back to the first node (head). This creates a continuous loop. Using both a `head` and a `tail` pointer allows for efficient  insertions at both ends.

## The Structure

Every node contains **Data** and a **Next** pointer. The circle is closed by the condition: `tail->next = head`.

```text
      +-------- head pointer --------+
      |                              |
      v                              |
    +---+      +---+      +---+      |
    | A | ---> | B | ---> | C | -----+
    +---+      +---+      +---+
                            ^
                            |
      +-------- tail pointer --------+

```

---

##  Insertion Operations

### 1. Insertion at the Beginning

**Goal:** Add a node so it becomes the new "entry point" of the circle.

* **Case A (Empty List):** The new node points to itself. Both `head` and `tail` point to it.
* **Case B (List with Elements):**
1. The new node's `next` is set to the current `head`.
2. The `head` pointer is moved to the new node.
3. The `tail->next` is updated to point to this new `head` to maintain the circle.



**ASCII Logic:**

```text
Step 1: [NewNode] ---> [Old Head]
Step 2: [Tail] ------> [NewNode]  (Maintaining Circle)
Step 3: Head = NewNode

```

---

### 2. Insertion at the End

**Goal:** Add a node after the current tail and make it the new tail.

* **Case A (Empty List):** Same as insertion at beginning.
* **Case B (List with Elements):**
1. The current `tail->next` (which was pointing to head) is changed to point to the `NewNode`.
2. The `NewNode->next` is set to point back to the `head`.
3. The `tail` pointer is moved to the `NewNode`.



**ASCII Logic:**

```text
Step 1: [Old Tail] ---> [NewNode]
Step 2: [NewNode]  ---> [Head]     (Closing Circle)
Step 3: Tail = NewNode

```

---

### 3. Insertion at a Specific Position

**Goal:** Insert a node at a given index `pos`.

* **Logic:**
1. Traverse the list using a `temp` pointer to find the node at `position - 1`.
2. Set `NewNode->next` to point where `temp->next` is currently pointing.
3. Set `temp->next` to point to the `NewNode`.
4. **Edge Case:** If `temp` happens to be the `tail`, update the `tail` pointer to the `NewNode`.



**ASCII Logic:**

```text
Before: [Node A] -----------> [Node B]
Action: [Node A] -> [NewNode] -> [Node B]

```

---


