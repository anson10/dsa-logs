#include <iostream>

struct Node
{
    int data;
    Node* next;
};

class circularLinkedList
{
    private:
    Node * head;

    public:
    circularLinkedList(): head(nullptr) {}

    //function to add a node
    void insert(int val)
    {
        Node* newNode = new Node();
        newNode -> data = val;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node* temp = head;
            while(temp->next != head)
            {
                temp = temp -> next;
            }
            temp -> next = newNode;
            newNode->next = head;
        }
    }

    void display()
    {
        Node* temp = head;

        if(head == nullptr)
        {
            std::cout<<"Empty list" << std::endl;
            return;
        }
        while(temp->next != head)
        {
            std::cout<<temp->data<<" ";
            temp = temp -> next;
        }
        std::cout<<temp->data <<std::endl;
    }
};

int main()
{
    circularLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    std::cout << "Elements: ";
    list.display();

    return 0;
}