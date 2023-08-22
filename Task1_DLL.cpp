#include <iostream>
using namespace std;

// Double Linked List

struct node
{
    int data;
    node *prev;
    node *next;
    node(int val) // Constructor
    {
        data = val;
        prev = nullptr;
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
    node *Mylist = new node(1); // Linked List Initialization
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

void insert_Beg(node *&head, int val)
{
    node *temp = new node(val);
    temp->next = head;
    if (head)
        head->prev = temp;
    head = temp;
}

void insert_End(node *&head, int val)
{
    node *temp = new node(val);
    node *current = head;
    while (current->next)
    {
        current = current->next;
    }
    temp->prev = current;
    current->next = temp;
}

void insert_by_pos(node *&head, int val, int position)
{
    node *temp = new node(val);
    node *current = head;
    if (position <= 0)
    {
        temp->next = head;
        if (head)
            head->prev = temp;
        head = temp;
    }
    else
    {
        for (int i = 1; i < position - 1; i++)
        {
            current = current->next;
        }
        temp->next = current->next;
        temp->prev = current;
        if (current->next)
            current->next->prev = temp;
        current->next = temp;
    }
}

void display(node *head)
{
    node *current = head;
    cout << "The contents of the linked list are :" << endl;
    while (current)
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
    if (!head)
        return;
    node *temp = head;
    head = head->next;
    if (head)
        head->prev = nullptr;
    free(temp);
}

void delete_End(node *&head)
{
    if (!head)
    {
        cout << "List is empty." << endl;
        return;
    }
    if (!head->next)
    {
        free(head);
        head = nullptr;
        return;
    }
    node *current = head;
    while (current->next->next)
    {
        current = current->next;
    }
    free(current->next);
    current->next = nullptr;
}

void delete_by_val(node *&head, int val)
{
    if (!head)
    {
        cout << "List is empty." << endl;
        return;
    }
    if (head->data == val)
    {
        node *temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        free(temp);
        return;
    }
    node *current = head;
    while (current->next && current->next->data != val)
    {
        current = current->next;
    }
    if (current->next)
    {
        node *del = current->next;
        current->next = del->next;
        if (del->next)
            del->next->prev = current;
        free(del);
    }
}

void delete_by_pos(node *&head, int pos)
{
    if (!head)
    {
        cout << "List is empty." << endl;
        return;
    }
    if (pos <= 0)
    {
        node *temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        free(temp);
        return;
    }
    node *current = head;
    for (int i = 1; i < pos && current; i++)
    {
        current = current->next;
    }
    if (current)
    {
        node *del = current;
        current->prev->next = current->next;
        if (current->next)
            current->next->prev = current->prev;
        free(del);
    }
}

void search_byval(node *&head, int val)
{
    int count = 1;
    node *temp = head;
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