#include <iostream>
#include <list>
#include <ctime>
using namespace std;

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


//For STL

// Operation : Insertion
void STL_insert_Beg(list<int> &lst, int val);
void STL_insert_End(list<int> &lst, int val);
void STL_insert_by_pos(list<int> &lst, int val, int position);

// Operation : Display
void STL_display(const list<int> &lst);

// Operation : Counting Nodes
void STL_count(const list<int> &lst);

// Operation : Deletion
void STL_delete_Beg(list<int> &lst);
void STL_delete_End(list<int> &lst);
void STL_delete_by_val(list<int> &lst, int val);
void STL_delete_by_pos(list<int> &lst, int pos);

// Operation : Search
void STL_search_byval(const list<int> &lst, int val);

int main()
{
    // For STL
    list<int> myList;
    clock_t start, end;
    cout<<"Using STL:"<<endl;
    start = clock();
    STL_insert_Beg(myList, 0);
    STL_insert_End(myList, 3);
    STL_insert_End(myList, 4);
    STL_insert_End(myList, 5);
    STL_insert_End(myList, 6);
    STL_insert_End(myList, 7);
    STL_insert_by_pos(myList, 2, 3);
    end = clock();
    cout << "Time taken for insertion: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    STL_display(myList);
    end = clock();
    cout << "Time taken for display: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    STL_delete_Beg(myList);
    STL_delete_End(myList);
    STL_delete_by_val(myList, 2);
    STL_delete_by_pos(myList, 0);
    end = clock();
    cout << "Time taken for deletions: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    STL_count(myList);
    end = clock();
    cout << "Time taken for counting: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    STL_search_byval(myList, 1);
    end = clock();
    cout << "Time taken for search: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    cout<< endl<< endl<< endl;
    cout<<"Without using STL:"<<endl;
    //Witout STL

    node *Mylist = new node(1); // Name of my Linked List is Mylist.

    start = clock();
    insert_Beg(Mylist, 0);
    insert_End(Mylist, 3);
    insert_End(Mylist, 4);
    insert_End(Mylist, 5);
    insert_End(Mylist, 6);
    insert_End(Mylist, 7);
    insert_by_pos(Mylist, 2, 3);
    end = clock();
    cout << "Time taken for insertion: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    delete_Beg(Mylist);
    delete_End(Mylist);
    delete_by_val(Mylist, 2);
    delete_by_pos(Mylist, 0);
    end = clock();
    cout << "Time taken for deletions: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    count(Mylist);
    end = clock();
    cout << "Time taken for counting: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    display(Mylist);
    end = clock();
    cout << "Time taken for display: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    search_byval(Mylist, 1);
    end = clock();
    cout << "Time taken for search: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}

//For STL
void STL_insert_Beg(list<int> &lst, int val)
{
    lst.push_front(val);
}

void STL_insert_End(list<int> &lst, int val)
{
    lst.push_back(val);
}

void STL_insert_by_pos(list<int> &lst, int val, int position)
{
    list<int>::iterator it = lst.begin();
    advance(it, position);
    lst.insert(it, val);
}

void STL_display(const list<int> &lst)
{
    cout << "The contents of the linked list are :" << endl;
    for (list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void STL_count(const list<int> &lst)
{
    cout << "The total number of nodes in the linked list are " << lst.size() << "." << endl;
}

void STL_delete_Beg(list<int> &lst)
{
    if (!lst.empty())
    {
        lst.pop_front();
    }
}

void STL_delete_End(list<int> &lst)
{
    if (!lst.empty())
    {
        lst.pop_back();
    }
}

void STL_delete_by_val(list<int> &lst, int val)
{
    lst.remove(val);
}

void STL_delete_by_pos(list<int> &lst, int pos)
{
    if (pos >= 0 && pos < lst.size())
    {
        list<int>::iterator it = lst.begin();
        advance(it, pos);
        lst.erase(it);
    }
}

void STL_search_byval(const list<int> &lst, int val)
{
    int count = 1;
    for (list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
    {
        if (*it == val)
        {
            cout << "Search Result: The data is at " << count << " position. (Considering first position as 1)" << endl;
            return;
        }
        count++;
    }
    cout << "Search Result: There is no data with the specified value." << endl;
}


// Without STL
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
