#include <iostream>

class Node {
    public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
    private:
    Node* head;

    public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while( current != nullptr) {
            Node* next = current -> next;
            delete current;
            current = next;
        }
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while(current -> next != nullptr) { 
            current = current -> next;
        }
        current-> next = newNode;
    }

    // Length of the List; Time Complexity will be O(n) as we will be visiting every node
    int countNodes() {
        int count = 0;          // Initialize a counter
        Node* current = head;   // Start traversal from the head

        // Traverse the list until the current pointer is nullptr
        while (current != nullptr) {
            count++;                // Increment the counter for the current node
            current = current->next; // Move to the next node
        }

        return count; // Return the final count
    }
    void display() {
        Node* current = head;
        std::cout << "List: ";
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << " -> ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() 
{
   LinkedList list;
    
    // 1. Initial length (empty list)
    std::cout << "Length of empty list: " << list.countNodes() << std::endl;
    
    // 2. Add elements
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.display(); // List: 10 -> 20 -> 30 -> 40
    
    // 3. Find length after insertion
    int length1 = list.countNodes();
    std::cout << "Length after 4 insertions: " << length1 << std::endl; // Output: 4
    
    // 4. Add one more element
    list.insertAtEnd(50);
    
    // 5. Find length again
    int length2 = list.countNodes();
    std::cout << "Length after 5 insertions: " << length2 << std::endl; // Output: 5
    
    return 0; 
}