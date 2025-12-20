#include <iostream>

class Node
{
    public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {};
};

class LinkedList
{
    Node *head;

    public:
    LinkedList(): head(nullptr) {};
    void insert(int val)
    {
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node *temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteAtBeginning()
    {
        if(head==nullptr)
        {
            std::cout<<"List is empty." <<std::endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        std::cout<<"Deleted from beginning" << std::endl;
    }
    void deleteAtEnd() {
        if (head == nullptr) {
            std::cout << "List is empty!" << std::endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = nullptr;
        delete temp;
        std::cout << "Deleted from end." << std::endl;
    }

    void deleteAtPos(int pos) {
        if (head == nullptr) {
            std::cout << "List empty!" << std::endl;
            return;
        }
        if (pos == 0) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            std::cout << "Position out of range!" << std::endl;
            return;
        }

        Node* nextNode = temp->next;
        temp->next = nextNode->next;
        delete nextNode;
        std::cout << "Deleted node at position " << pos << std::endl;
    }

    void display() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main() {
    LinkedList list;
    int choice, val, pos;

    // Initial setup
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    do {
        std::cout << "\n Current List " << std::endl;
        list.display();
        std::cout << "1. Delete Beginning\n2. Delete End\n3. Delete Position\n0. Exit\nChoice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: list.deleteAtBeginning(); break;
            case 2: list.deleteAtEnd(); break;
            case 3:
                std::cout << "Enter position: ";
                std::cin >> pos;
                list.deleteAtPos(pos);
                break;
        }
    } while (choice != 0);

    return 0;
}