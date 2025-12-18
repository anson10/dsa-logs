#include<iostream>

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = nullptr;
struct node *temp = nullptr;

void create()
{
    int choice = 1;
    head = nullptr; // init head as empty

    while(choice)
    {
        //using dynamic memory allocation
        struct node *newnode = new struct node();

        std::cout<<"Enter Data: "<< std::endl;
        std::cin>> newnode->data;

        newnode -> prev = nullptr;
        newnode -> next = nullptr;

        if(head == nullptr){
            head = temp = newnode;
        } else {
            //link the new node to the end of the list
            temp -> next = newnode;
            newnode -> prev  = temp;
            temp = newnode;
        }

        std::cout<<"Want to continue (0 or 1)? ";
        std::cin>>choice;
    }
}

void display()
{
    struct node *ptr;
    ptr = head;

    while(ptr != nullptr)
    {
        std::cout<< ptr->data << " ";
        ptr = ptr -> next;
    }
     std::cout<<std::endl;

}

int main()
{
    create();
    display();
    return 0;
}


