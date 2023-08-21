// The code counts number of nodes in the linked list.(Traversing is used making the code ineffcient.)
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

void insert(node *&head, int val);
void count(node* head);
int main()
{
    node* Mylist=new node(3);
    // Mylist->data=4;
    insert(Mylist, 4);
    insert(Mylist, 5);
    count(Mylist);
    return 0;
}

void insert(node *&head, int val)
{
    node *list=new node(val);
    if (!head)
    {
        head = list;
    }
    else
    {
        node* travel;
        travel=head;
        while(travel->next)
        {
            travel=travel->next;
        }
        travel->next=list;
    }
}
void count(node* head)
{   
    int count=0;
    node* current=head;
    while(current)
    {
        current=current->next;
        count++;
    }
    cout<<count<<endl;
}