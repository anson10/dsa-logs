#include <iostream>

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

Node* reverseDLL(Node* head)
{
    if (head == nullptr || head->next == nullptr) {
        return head; // List is empty or has only one node
    }

    Node* current = head;
    Node* temp = nullptr;
    
    // Traverse the list and swap next and prev for all nodes
    while(current!=nullptr)
    {
        //swap pointers
        temp = current -> prev;
        current->prev = current ->next;
        current->next = temp;

        current = current -> prev;
    }

    // after the loop, temp point to the previous head
    // new node is the node that was the last node in the original list

    return temp->prev;
}

void printList(Node* head)
{
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    if ((*head_ref) != nullptr) {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
}

int main() {
    Node* head = nullptr;

    // Create list: 10 <-> 20 <-> 30 <-> 40
    push(&head, 40);
    push(&head, 30);
    push(&head, 20);
    push(&head, 10);

    std::cout << "Original List: ";
    printList(head);

    head = reverseDLL(head);

    std::cout << "Reversed List: ";
    printList(head);

    return 0;
}

/*
temp = current->prev;        // 1. Put the "Left arm" address in a temporary pocket
current->prev = current->next; // 2. Move the "Right arm" address to the Left arm
current->next = temp;        // 3. Put the address from your pocket into the Right arm
*/