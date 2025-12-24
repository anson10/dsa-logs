#include <iostream>

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList() : tail(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node{val, nullptr};
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void reverse() {
        // LOGIC: If list is empty or has only one node, no reversal needed.
        if (tail == nullptr || tail->next == tail) {
            return; 
        }

        /* LOGIC: We need three pointers to flip the links without losing the list.
           1. current: The node we are currently redirecting.
           2. prev: The node that 'current' should point to.
           3. nextNode: A temporary pocket to hold the rest of the list.
        */
        Node *prev = tail;             // Initially, the head will point back to the tail.
        Node *current = tail->next;    // Start with the head (tail->next).
        Node *nextNode = nullptr;
        Node *oldHead = tail->next;    // Remember the old head; it will become the NEW tail.

        /*
           LOGIC: Loop through the circle.
           In each step, we take the node's forward pointer and point it backward.
        */
        do {
            // 1. Save the next node before we break the link.
            nextNode = current->next; 
            
            // 2. REVERSE: Point the current node's arm backward to 'prev'.
            current->next = prev;     
            
            // 3. SLIDE: Move 'prev' and 'current' one step forward for the next iteration.
            prev = current;           
            current = nextNode;       
        } while (current != oldHead); // Stop once we have circled back to the starting node.

        /*
           LOGIC: Finalizing the Tail.
           In a circular list, the tail is just a label. 
           After reversal, the node that WAS the head is now the last node.
        */
        tail = oldHead; 
        std::cout << "List reversed successfully." << std::endl;
    }

    void display() {
        if (!tail) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = tail->next;
        do {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        std::cout << "(head)" << std::endl;
    }
};

int main() {
    CircularLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);

    std::cout << "Before: ";
    list.display();

    list.reverse();

    std::cout << "After:  ";
    list.display();

    return 0;
}