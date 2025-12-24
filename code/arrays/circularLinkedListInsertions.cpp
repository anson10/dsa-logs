#include <iostream>

struct Node
{
    int data;
    Node* next;
};

class circularLinkedList
{
    private:
    Node *head, *tail;

    public:
    //constructor initialises pointers to null
    circularLinkedList() : head(nullptr), tail(nullptr) {};

    /*
    Create a new node.

    Point its next to the current head.

    Update tail->next to point to the new node.

    Move the head pointer to the new node.
    */
    void insertAtBeg(int val)
    {
        Node *newNode = new Node();
        newNode->data = val;

        if(head==nullptr)
        {
            head=tail=nullptr;
            newNode->next = head;
        }
        else
        {
            newNode -> next = head;
            head = newNode;
            tail->next = newNode;       
        }
        std::cout<<"Inserted " << val << " at the start" << std::endl;
    }

    void insertAtEnd(int val)
    {
        /*
        Point the current tail->next to the new node.

        Point the new node's next to head.

        Move the tail pointer to the new node.
        */
        Node *newNode = new Node();
        newNode->data = val;
        if(head == nullptr)
        {
            head = tail = newNode;
            newNode->next = head;
        }
        else
        {
            tail->next = newNode;
            tail=newNode;
            tail->next = head;
        }
        std::cout << "Inserted " << val << " at the end." << std::endl;
    }
    void insertAtPos(int val, int pos)
    {   
        /*
        Traverse to the node before the target position (let's call it temp).

        New node points to temp->next.

        temp points to the new node.
        */
        if(pos<=0)
        {
            insertAtBeg(val);
            return;
        }
        Node *newNode = new Node();
        newNode->data = val;

        Node* temp = head;
        for(int i=0; i<pos-1; i++)
        {
            temp = temp->next;
            if(temp==head) {
                std::cout<<"Inserting at End." <<std::endl;
                insertAtEnd(val);
                return;
            }
        }
        newNode -> next = temp->next;
        temp->next = newNode;

        //update the tail pointer
        if(temp == tail)
        {
            tail = newNode;
        }
        std::cout<<"Inserted " << val <<" at position "<< pos << std::endl;
    }
    void display()
    {
        if(head==nullptr)
        {
            std::cout<<"list is empty" << std::endl;
            return;
        }
        Node *temp =head;
        std::cout<<"Elements:";
        do {
            std::cout<<temp->data << "-> ";
            temp = temp->next;
        } while(temp!=head);

        std::cout << "(back to head: " << head->data << ")" << std::endl;
    }
};

int main() {
    circularLinkedList list;

    // Test cases
    list.insertAtEnd(10);    
    list.insertAtEnd(20);    
    list.insertAtBeg(5);     
    list.insertAtPos(15, 3); 

    list.display();

    return 0;
}