#include <iostream>
using namespace std;

//Single Linked List

struct node
{
	int data;
	node* next;
	node(int val)   // Making a constructor.
	{
		data=val;
		next=nullptr;
	}
};
// Operation : Insertion
void insert_Beg(node* &head, int val);
void insert_End(node* &head, int val);
void insert_X(node* &head, int val, int position);
// Operation : Display
void display(node *head);
// Operation : Count
void count(node* head);

int main()
{
	node* Mylist=new node(1);    //Name of my Linked List is Mylist.
	insert_Beg(Mylist, 0);
	insert_End(Mylist, 3);
	insert_X(Mylist, 2, 3);
	display(Mylist);
	count(Mylist);
	return 0;
}


void insert_Beg(node* &head, int val)           // This is pass by reference.
{
    node *temp=new node(val);
    temp->next= head;
    head=temp;
}

void insert_End(node* &head, int val)
{
	node *temp = new node(val);
	node* current =head;
	while(current->next)		// current->next = nullptr means false for while loop.
	{
		current=current->next;
	}
	current->next =temp;
}

void insert_X(node *&head, int val, int position)
{	
    node *temp = new node(val);
    node *current = head;
    if(position<=0)
    {
    	temp->next= head;
    	head=temp;
    }
    else
    {
	for (int i = 1; i < position - 1; i++)
	{
	    current = current->next;
	}
	
	temp->next = current->next;
	current->next = temp;
    }
}

void display(node *head)
{
    node *current = head;
    cout<<"The contents of the linked list are :" <<endl;
    while (current)		//when current turns to be nullptr no node is left.
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
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
    cout<<"The total number of nodes in the linked list are "<<count<<"."<<endl;
}
