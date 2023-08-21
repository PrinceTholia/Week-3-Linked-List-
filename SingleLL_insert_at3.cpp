// Inserting a node at given location.
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = nullptr;
    }
};

void insert_X(node *&head, int val, int position);
node *add_at_the_end(node *ptr, int val);
int main()
{
    node *mylist = new node(0);
    node *ptr = mylist;
    ptr = add_at_the_end(ptr, 4);
    ptr = add_at_the_end(ptr, 5);
    ptr = add_at_the_end(ptr, 6);
    ptr = add_at_the_end(ptr, 7);
    ptr = add_at_the_end(ptr, 8);
    insert_X(mylist, 2, 2);
    insert_X(mylist, 3, 3);
    insert_X(mylist, 1, 1);
    insert_X(mylist, 9, 0);
    ptr = mylist;
    while (ptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;

}

// This is pass by value.
node *add_at_the_end(node *ptr, int val)
{
    node *temp = new node(val);
    ptr->next = temp;
    return temp;
}

void insert_X(node *&head, int val, int position)
{
    if(position<=0){position=1;cout<<endl<<position<<endl;}
    
    node *temp = new node(val);
    node *current = head;
    for (int i = 1; i < position - 1; i++)
    {
        current = current->next;
    }
    temp->next = current->next;
    current->next = temp;
        
}
