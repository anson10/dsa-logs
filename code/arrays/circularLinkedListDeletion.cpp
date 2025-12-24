#include <iostream>

struct Node {
    int data;
    Node* next;
};

class circularLinkedLists
{
    private:
    Node* tail;

    public:
    circularLinkedLists() {tail = nullptr; }

    void insert(int val)
    {
        Node* newNode = new Node{val, nullptr};
        if (!tail) 
        {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode -> next = tail -> next;
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void deleteFromBeg()
    {
        if (!tail) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* head = tail->next; 
        if (head == tail) { // Only one node
            delete head;
            tail = nullptr;
        } else {
            tail->next = head->next; // Tail skips over the old head
            std::cout << "Deleted from beginning: " << head->data << std::endl;
            delete head;
        }
    }

    void deleteFromEnd() {
        if (!tail) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* head = tail->next;
        if (head == tail) { // Only one node
            delete tail;
            tail = nullptr;
        } else {
            Node* temp = head;
            // Traverse to find the node BEFORE the tail
            while (temp->next != tail) {
                temp = temp->next;
            }
            // Now 'temp' is the second-to-last node
            temp->next = head; // New tail points to head
            std::cout << "Deleted from end: " << tail->data << std::endl;
            delete tail;
            tail = temp; // Update tail pointer
        }
    }
    void deleteAtPos(int pos) {
        if (!tail) return;
        if (pos == 1) {
            deleteFromBeg();
            return;
        }

        Node* head = tail->next;
        Node* curr = head;
        Node* prev = nullptr;

        for (int i = 1; i < pos; i++) {
            prev = curr;
            curr = curr->next;
            if (curr == head) {
                std::cout << "Position out of bounds." << std::endl;
                return;
            }
        }

        prev->next = curr->next;
        if (curr == tail) {
            tail = prev; // Update tail if we deleted the last node
        }
        std::cout << "Deleted from position " << pos << ": " << curr->data << std::endl;
        delete curr;
    }
    void display() {
        if (!tail) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = tail->next; // Start from head
        do {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        std::cout << "(back to head)" << std::endl;
    }
};

int main() {
    circularLinkedLists list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    std::cout << "Initial List: ";
    list.display();

    list.deleteFromBeg();
    list.display();

    list.deleteFromEnd();
    list.display();

    list.deleteAtPos(2);
    list.display();

    return 0;
}