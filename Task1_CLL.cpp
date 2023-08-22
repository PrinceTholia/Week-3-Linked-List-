#include <iostream>
using namespace std;

// Circular Linked List

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
void search_byval(node *head, int val);

int main()
{
    node *Mylist = nullptr; // Circular linked list starts as empty
    insert_End(Mylist, 1); // Inserting at end
    insert_Beg(Mylist, 0); // Inserting at beginning
    insert_End(Mylist, 3);
    insert_End(Mylist, 4);
    insert_End(Mylist, 5);
    insert_End(Mylist, 6);
    insert_End(Mylist, 7);
    insert_by_pos(Mylist, 2, 3); // Inserting at a specific position
    delete_Beg(Mylist); // Deleting from the beginning
    delete_End(Mylist); // Deleting from the end
    delete_by_val(Mylist, 2); // Deleting by value
    delete_by_pos(Mylist, 0); // Deleting by position
    count(Mylist);
    display(Mylist);
    search_byval(Mylist, 1);
    return 0;
}

void insert_Beg(node *&head, int val)
{
    node *temp = new node(val);
    if (head == nullptr)
    {
        temp->next = temp; // Circular reference for single node
    }
    else
    {
        node *current = head;
        while (current->next != head) // Traverse to the last node
        {
            current = current->next;
        }
        current->next = temp; // Link last node to the new node
        temp->next = head; // Link new node to the first node
    }
    head = temp; // Update head to the new first node
}

void insert_End(node *&head, int val)
{
    node *temp = new node(val);
    if (head == nullptr)
    {
        temp->next = temp; // Circular reference for single node
        head = temp;
    }
    else
    {
        node *current = head;
        while (current->next != head) // Traverse to the last node
        {
            current = current->next;
        }
        current->next = temp; // Link last node to the new node
        temp->next = head; // Link new node to the first node
    }
}

void insert_by_pos(node *&head, int val, int position)
{
    if (position <= 0)
    {
        insert_Beg(head, val);
    }
    else
    {
        node *temp = new node(val);
        node *current = head;
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
    if (head == nullptr)
    {
        cout << "The circular linked list is empty." << endl;
    }
    else
    {
        node *current = head;
        cout << "The contents of the circular linked list are :" << endl;
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
}

void count(node *head)
{
    if (head == nullptr)
    {
        cout << "The circular linked list is empty." << endl;
        return;
    }

    int count = 0;
    node *current = head;
    do
    {
        current = current->next;
        count++;
    } while (current != head);
    cout << "The total number of nodes in the circular linked list are " << count << "." << endl;
}

void delete_Beg(node *&head)
{
    if (head == nullptr)
    {
        cout << "The circular linked list is empty." << endl;
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = nullptr;
    }
    else
    {
        node *temp = head;
        node *current = head;
        while (current->next != head) // Traverse to the last node
        {
            current = current->next;
        }
        head = head->next; // Update head to the next node
        current->next = head; // Link last node to the new first node
        free(temp);
    }
}

void delete_End(node *&head)
{
    if (head == nullptr)
    {
        cout << "The circular linked list is empty." << endl;
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = nullptr;
    }
    else
    {
        node *current = head;
        node *prev = nullptr;
        while (current->next != head) // Traverse to the last node
        {
            prev = current;
            current = current->next;
        }
        prev->next = head; // Link second last node to the new first node
        free(current);
    }
}

void delete_by_val(node *&head, int val)
{
    if (head == nullptr)
    {
        cout << "The circular linked list is empty." << endl;
        return;
    }

    if (head->next == head && head->data == val)
    {
        free(head);
        head = nullptr;
    }
    else
    {
        node *current = head;
        node *prev = nullptr;
        do
        {
            if (current->data == val)
            {
                if (prev == nullptr) // Deleting from the beginning
                {
                    delete_Beg(head);
                    return;
                }
                else
                {
                    prev->next = current->next;
                    free(current);
                    return;
                }
            }
            prev = current;
            current = current->next;
        } while (current != head);
        cout << "Value not found in the circular linked list." << endl;
    }
}

void delete_by_pos(node *&head, int pos)
{
    if (head == nullptr)
    {
        cout << "The circular linked list is empty." << endl;
        return;
    }

    if (pos <= 0)
    {
        delete_Beg(head);
    }
    else
    {
        node *current = head;
        node *prev = nullptr;
        for (int i = 1; i < pos; i++)
        {
            prev = current;
            current = current->next;
            if (current == head) // Reached end of the list
            {
                cout << "Position out of bounds." << endl;
                return;
            }
        }

        if (current->next == head) // Deleting the last node
        {
            delete_End(head);
            return;
        }

        prev->next = current->next;
        free(current);
    }
}

void search_byval(node *head, int val)
{
    if (head == nullptr)
    {
        cout << "The circular linked list is empty." << endl;
        return;
    }

    node *temp = head;
    int count = 1;

    do
    {
        if (temp->data == val)
        {
            cout << "Search Result: The data is at " << count << " position." << endl;
            return;
        }
        temp = temp->next;
        count++;
    } while (temp != head);

    cout << "Search Result: There is no data with the specified value." << endl;
}
