#include <iostream>
using namespace std;
//We have used constructor in struct node
struct node
{
    int data;
    node *next;

    node(int val)    // The Constructor
    {
        data = val;
        next = nullptr;
    }
};

void insert(node *&head, int val);
void display(node *head);

int main()
{
    int x;
    node *Mylist = nullptr;
    cout << "Enter numbers in you list" << endl;
    insert(Mylist,4);
    display(Mylist);
    return 0;
}

void insert(node *&head, int val)
{

    node *aNode = new node(val);
    if (!head)
    {
        head = aNode;
    }
    else
    {
        node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = aNode;
    }
}
void display(node *head)
{
    node *current = head;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}