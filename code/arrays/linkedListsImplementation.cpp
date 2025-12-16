#include <iostream>

class Node {
    public:
    int data; //data part of the node
    Node *next; // Pointer to the next node 

    //Constructor
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList{
    private:
    Node* head;

    public:
    //Constructor
    LinkedList() : head(nullptr) {}

    //Destructor
    ~LinkedList() {
        Node* current = head;
        // Delete each node to prevent the memory leaks
        while(current != nullptr) {
            Node* next = current-> next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
    void setHead(Node* newHead) {
    head = newHead;
}

void display() {
    Node* current = head;
    if(current == nullptr){
        std::cout<<"List is empty " << std::endl;
        return;
    }
    std::cout<<"List: ";
    while(current != nullptr){
        std::cout << current -> data;
        if (current-> next != nullptr){
            std::cout <<" -> ";
        }
        current = current -> next;
    }
    std::cout << std::endl;
}
};
int main() {
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);

    // Linking nodes together
    node1 -> next = node2;
    node2 -> next = node3;

    LinkedList list;
    // setting starting point head
    list.setHead(node1);
    std::cout << "Demonstrating traversal of the linked list structure:" << std::endl;
    list.display();

    return 0;


}