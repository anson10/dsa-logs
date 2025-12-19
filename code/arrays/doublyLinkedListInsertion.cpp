#include<iostream>

struct node
{
    int data;
    node *prev;
    node *next;
};

//global pointers
node *head = nullptr;
node *tail = nullptr;

//insertion at beginning
void insertAtBeginning()
{
    node *newnode = new node();

    std::cout << "Enter data to append it to the beginning: ";
    std::cin >> newnode -> data;

    newnode -> prev = nullptr;
    newnode -> next = head;

    if (head == nullptr)
    {
        head = tail = newnode;
    } else {
        head -> prev = newnode;  //link old head to new node
        head = newnode;
    }
}

//insertion at the end
void insertAtEnd()
{
    node *newnode = new node();
    std::cout << "Enter data to append it to the end: ";
    std::cin >> newnode-> data;

    if (head == nullptr)
    {
        newnode->prev =nullptr;
        head = tail = newnode;
    } else {
        tail -> next = newnode;
        newnode-> prev = tail;
        tail = newnode;
    }
}

/*
insertion at a specific position
1. traverse to the node before the target position. call it temp
2. link newnode->next to temp->next
3. link newnode->prev to temp
4. link temp->next->prev to newnode
5. finally, link temp->next to newnode
*/

void insertAtPos()
{
    int pos, i=0;
    std::cout<<"Enter position: ";
    std::cin >> pos;

    if(pos == 0)
    {
        insertAtBeginning();
    }
    else{
        node *newnode = new node();
        node *temp = head;

        std::cout<<"Enter data: ";
        std::cin >> newnode -> data;

        //traverse to pos
        while(i<pos-1 && temp!=nullptr)
        {
            temp = temp->next;
            i++;
        }
        if(temp == nullptr || temp -> next ==nullptr)
        {
            insertAtEnd();
        } 
        else 
        {
            newnode -> next = temp -> next;
            newnode -> prev = temp;
            temp -> next->prev = newnode;
            temp->next = newnode;
        }
    }
}

void display()
{
    node *temp = head;
    if (head == nullptr) {
        std::cout << "List is empty!" << std::endl;
        return;
    }

    std::cout<<"List :";
    while (temp != nullptr) {
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    }
    std::cout<<"NULL" <<std::endl;
}

void create() {
    int choice = 1;
    while (choice) {
        node *newnode = new node();
        std::cout << "Enter data: ";
        std::cin >> newnode->data;
        newnode->next = nullptr;
        newnode->prev = nullptr;

        if (head == nullptr) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        std::cout << "Add another node? (1/0): ";
        std::cin >> choice;
    }
}

int main() {
    int choice;
    create();
    
    while (true) {
        std::cout << "\n1. Insert Beg\n2. Insert End\n3. Insert Pos\n4. Display\n5. Exit\nChoice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: insertAtBeginning(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAtPos(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: std::cout << "Invalid!";
        }
    }
    return 0;
}