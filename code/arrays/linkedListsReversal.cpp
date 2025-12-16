#include <iostream>

class Node {
    public:
    int data;
    Node * next;

    Node(int val) : data(val), next(nullptr) {};
};

class LinkedList {
    private:
    Node* head;

    public:
    LinkedList() : head(nullptr) {}

    void insertAtEnd(int data)
    {
        Node* newNode = new Node(data);
        if (head == nullptr) 
        {
             head = newNode;
             return;
        }
        Node* current = head;
        while (current -> next != nullptr) {
            current = current -> next;
        }
        current -> next = newNode;
    }
        void display()
        {
            Node* current = head;
            std::cout << "List: ";
            while(current != nullptr)
            {
                std::cout<<current-> data;
                if (current -> next != nullptr) {
                    std::cout << "-> " ;
                }
                current = current -> next;
            }
            std::cout<< std::endl;
        }
    // Reversing the Linked List; Time Complexity : O(n)
    void reverse()
    {
        //initialise three pointers
        Node* current = head; //pointer to the current node being processed
        Node* prev = nullptr;
        Node* next = nullptr;

        // loop through the list
        while(current != nullptr)
        {
            //save the next node  to avoid losing the rest of the list
            next = current -> next;

            // make the current node point backwards to prev
            current -> next = prev;

            //advance prev and current one step forward
            prev = current; //prev moved to current node
            current = next; // current is moved to the saved next node
        }
        head = prev; // prev is pointing to the new first node

    }  
};

int main() 
{
    LinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);

    std::cout << "Original List: ";
    list.display();

    list.reverse();

    std::cout << "Reversed List";
    list.display();

    return 0;
}
