#include <iostream>
using namespace std;

// Single Linked List

struct node
{
    int data;
    node *next;
    node(int val) // Making a constructor.
    {
        data = val;
        next = nullptr;
    }
};

// Operation : Insertion
void insert_Beg(node *&head, int val);
void insert_End(node *&head, int val);
void insert_by_pos(node *&head, int val, int position);
// Operation : Display
void display(node *head);
// Operation : Counting Nodes
void count(node *head);
// Operation : Deletion
void delete_Beg(node *&head);
void delete_End(node *&head);
void delete_by_val(node *&head, int val);
void delete_by_pos(node *&head, int pos);
// Operation : Search
void search_byval(node *&head, int val);

int main()
{
    node *Mylist = new node(1); // Name of my Linked List is Mylist.
    insert_Beg(Mylist, 0);
    insert_End(Mylist, 3);
    insert_End(Mylist, 4);
    insert_End(Mylist, 5);
    insert_End(Mylist, 6);
    insert_End(Mylist, 7);
    insert_by_pos(Mylist, 2, 3);
    delete_Beg(Mylist);
    delete_End(Mylist);
    delete_by_val(Mylist, 2);
    delete_by_pos(Mylist, 0);
    count(Mylist);
    display(Mylist);
    search_byval(Mylist, 1);
    return 0;
}

void insert_Beg(node *&head, int val) // This is pass by reference.
{
    node *temp = new node(val);
    temp->next = head;
    head = temp;
}

void insert_End(node *&head, int val)
{
    node *temp = new node(val);
    node *current = head;
    while (current->next) // current->next = nullptr means false for while loop.
    {
        current = current->next;
    }
    current->next = temp;
}

void insert_by_pos(node *&head, int val, int position) // Note: Head is considered as position 0
{
    node *temp = new node(val);
    node *current = head;
    if (position <= 0)
    {
        temp->next = head;
        head = temp;
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
    cout << "The contents of the linked list are :" << endl;
    while (current) // when current turns to be nullptr no node is left.
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void count(node *head)
{
    int count = 0;
    node *current = head;
    while (current)
    {
        current = current->next;
        count++;
    }
    cout << "The total number of nodes in the linked list are " << count << "." << endl;
}

void delete_Beg(node *&head)
{
    node *temp = head;
    head = head->next;
    free(temp);
}

void delete_End(node *&head)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
    }
    else if (head->next == nullptr)
    {
        free(head);
        head = nullptr;
    }
    else
    {
        node *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = nullptr;
    }
}

void delete_by_val(node *&head, int val)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
    }
    else if (head->next == nullptr)
    {
        free(head);
        head = nullptr;
    }
    else
    {
        node *temp = head;
        while (temp->next->data != val)
        {
            temp = temp->next;
        }
        node *del = temp->next;
        temp->next = temp->next->next;
        free(del);
    }
}

void delete_by_pos(node *&head, int pos) // Note: Head is considered as position 0
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
    }
    else if (head->next == nullptr)
    {
        free(head);
        head = nullptr;
    }
    else if(pos >0)
    {
        node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp=temp->next;
        }
        node *del = temp->next;
        temp->next = temp->next->next;
        free(del);
    }
    else
    {
        node *temp = head;
        head = head->next;
        free(temp);
    }
}

void search_byval(node *&head, int val)
{
    int count = 1;
    node* temp = head;
    
    // Iterate through the linked list until you find the desired value or reach the end
    while (temp != nullptr && temp->data != val)
    {
        count++;
        temp = temp->next;
    }
    
    if (temp != nullptr)
    {
        cout << "Search Result: The data is at " << count << " position. (Considering first position as 1)" << endl;
    }
    else
    {
        cout << "Search Result: There is no data with the specified value." << endl;
    }
}