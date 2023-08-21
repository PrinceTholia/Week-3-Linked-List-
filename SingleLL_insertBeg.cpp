// No traversing and we can add value a the initial point i.e. Head
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

void insert_Beg(node* &head, int val);
node* add_at_the_end(node* ptr, int val);
int main()
{
    node* mylist=new node(3);
    node* ptr=mylist;
    ptr=add_at_the_end(ptr, 4);
    ptr=add_at_the_end(ptr, 5);
    ptr=add_at_the_end(ptr, 6);
    ptr=add_at_the_end(ptr, 7);
    ptr=add_at_the_end(ptr, 8);
    insert_Beg(mylist,2);
    insert_Beg(mylist,1);
    insert_Beg(mylist,0);
    ptr=mylist;
    while(ptr){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
    return 0;
}

//This is pass by value.
node* add_at_the_end(node* ptr, int val){
    node*temp=new node(val);
    ptr->next=temp;
    return temp;
}
// node* insert_Beg(node* head, int val){
//     node*temp=new node(val);
//     temp->next=head;
//     head=temp;
//     return head;
// }

//hi
// This is pass by reference.
void insert_Beg(node* &head, int val){
    node *temp=new node(val);
    temp->next= head;
    head=temp;
}
