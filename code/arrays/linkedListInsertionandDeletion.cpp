#include <iostream>

class Node
{
public:
    int data; // data part of the node
    Node* next; // pointer to the next Node

    // Constructor
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
    private:
    Node* head; //points to the first node of the list

    public:
    // Initialises an empty list
    LinkedList() : head(nullptr) {} ;

    // Destructor to prevent memory leaks
    ~LinkedList () {
        Node* current = head; 
        while( current != nullptr) {
            Node* next = current -> next;
            delete current;
            current = next;
        }
        head = nullptr;

    }

    // Insertion at the Beginning
    // Take O(1) time

    void insertAtBeginning(int data) 
    {
        Node *newNode = new Node(data); //create and allocate memory for the new node
        newNode -> next = head; //points to current head
        head = newNode; //Updated it to the new node, making it the new start

    }
    
    // Insertion at the End (requires Traversal)
    //  Takes O(n) time

    void insertAtEnd(int data) 
    {
        Node *newNode = new Node(data);

        //Case 1: if list is empty , the new node becomes the head
        if (head == nullptr) {
            head = newNode;
            return;
        }

        //Case 2: if list not empty, traverse to the end
        Node* current = head;

        while(current -> next != nullptr) //move till current is the last node
        { 
            current = current -> next;
        };
        current-> next = newNode;
    } 

        // Case 3: Insertion at any position 
        // Takes O(n) time

        void insertAtPosition(int data, int position)
        {
            if (position < 0) {
                std::cout << "Error: Position must be 0 or greater " << std::endl;
                return;
            }
            if(position ==1)  //if insertion at first position, reuse insertAtBeginning func
            {
                insertAtBeginning(data);
                return;
            }

            Node* newNode = new Node(data); //create node
            Node * current = head; //Start traversal

            // traverse till current is the node before the target position
            for (int i=0; i< position-1 && current != nullptr; i++)
            {current = current -> next;};

            // check if the position is out of bounds

            if(current == nullptr) 
            {
                std::cout << " Error: Position " << position << "is beyound the list size "<< std::endl;
                delete newNode;
                return;
            }
            newNode -> next = current -> next;
            current -> next = newNode;
            
        }
      void display() 
      {
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
    
    // Deletion at beginning - Takes O(1) time
    void deleteAtBeginning() {
        if (head == nullptr)
        {
            std::cout<<"Cannot delete an empty list" << std::endl;
            return;
        }
        Node* temp = head; // address of the node to be deleted
        head = head -> next; // update the point to the next node
        
        delete temp; //free the memory of the old head
    }

    // Deletion at the end
    void deleteAtEnd() {
        //empty list
        if(head == nullptr) {
            std::cout<<"Cannot delete empty list" << std::endl;
        }
        // if only one node is present
        if (head -> next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        // if list has 2 or more nodes
        Node* current = head;

        // loop stops when current->next->next is nullptr
        while(current->next->next != nullptr)
        {
            current = current->next;
        }
        //save the address of the node to be deleted
        Node* temp = current -> next;
        //unlink the last node by setting the second to last node's next to nullptr
        current->next = nullptr;

        delete temp;
    }

    void deleteAtPosition(int position)
    {
        if (position < 0 || head == nullptr)
        {
            std::cout<<"Error: Invalid Position" << std::endl;
            return;
        }
        if(position == 1)
        {
            deleteAtBeginning();
            return;
        }
        //traverse to the node before the target node
        Node* current = head;
        for (int i=1; i<position -1 && current != nullptr; i++)
        {
            current = current->next;
        }

        //if position is too large 
        if (current == nullptr || current ->next ==nullptr)
        {
        std::cout << "Error: Position " << position << " is beyond the list size." << std::endl;
        return;
        }
        //address of the node to be deleted
        Node* temp = current -> next;

        //unlink the target node
        current->next = temp -> next;

        delete temp;
    }

};


int main() {
    LinkedList list;
    
    std::cout << " Insertion at Beginning " << std::endl;
    list.insertAtBeginning(10); 
    list.insertAtBeginning(5);  
    list.display(); // Expected: 5 -> 10

    std::cout << "\nInsertion at End" << std::endl;
    list.insertAtEnd(30);  
    list.insertAtEnd(40);  
    list.display(); // Expected: 5 -> 10 -> 30 -> 40
    
    std::cout << "\nInsertion at Any Point " << std::endl;
    list.insertAtPosition(20, 3); // Insert 20 at position 3
    list.display(); // Expected: 5 -> 10 -> 20 -> 30 -> 40

    list.insertAtPosition(1, 1);  // Insert 1 at position 1 (new head)
    list.display(); // Expected: 1 -> 5 -> 10 -> 20 -> 30 -> 40
    
    list.insertAtPosition(50, 8); // Test out of bounds 
    
    std::cout<<"\n DELETION OF ELEMENTS";
    std::cout << "\nDelete at Beginning" << std::endl;
    list.deleteAtBeginning();

    std::cout << "\nDelete at End" << std::endl;
    list.deleteAtEnd();
    list.display(); 

    std::cout << "\n Delete at Position (2) ---" << std::endl;
    list.deleteAtPosition(2); // Delete '30'
    list.display(); // Expected: 20 -> 40

    std::cout << "\nFinal Clean-up " << std::endl;
    list.deleteAtBeginning();  
    list.deleteAtEnd();      
    list.display();
    return 0;
}