#include <iostream>
using namespace std;

// Struct to represent a task in the To-Do List
struct TaskList
{
    int task_num;
    string taskDescription;
    TaskList *next;
    TaskList(int num, const string &desc)
    {
        task_num = num;
        taskDescription = desc;
        next = nullptr;
    }
};

// Function prototypes for various operations
void insert_Beg(TaskList *&head, int num, const string &desc);
void insert_End(TaskList *&head, int num, const string &desc);
void display(TaskList *head);
void count(TaskList *head);
void delete_Beg(TaskList *&head);
void delete_End(TaskList *&head);
void delete_by_val(TaskList *&head, int num);
void delete_by_pos(TaskList *&head, int pos);
void search_byval(TaskList *&head, const string &desc);

int main()
{
    TaskList *MyTaskList = new TaskList(1, "Complete assignment");
    insert_Beg(MyTaskList, 0, "Wake up");
    insert_End(MyTaskList, 3, "Lunch");
    insert_End(MyTaskList, 4, "Study");
    insert_End(MyTaskList, 5, "Exercise");
    insert_End(MyTaskList, 6, "Dinner");
    insert_End(MyTaskList, 7, "Read book");
    delete_Beg(MyTaskList);
    delete_End(MyTaskList);
    delete_by_val(MyTaskList, 2);
    delete_by_pos(MyTaskList, 0);
    count(MyTaskList);
    display(MyTaskList);
    search_byval(MyTaskList, "Study");
    return 0;
}

// Function to insert a task at the beginning of the list
void insert_Beg(TaskList *&head, int num, const string &desc)
{
    TaskList *temp = new TaskList(num, desc);
    temp->next = head;
    head = temp;
}

// Function to insert a task at the end of the list
void insert_End(TaskList *&head, int num, const string &desc)
{
    TaskList *temp = new TaskList(num, desc);
    TaskList *current = head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = temp;
}

// Function to display the tasks in the list
void display(TaskList *head)
{
    TaskList *current = head;
    cout << "To-Do List:" << endl;
    while (current)
    {
        cout << current->task_num << ". " << current->taskDescription << endl;
        current = current->next;
    }
    cout << endl;
}

// Function to count the total number of tasks in the list
void count(TaskList *head)
{
    int count = 0;
    TaskList *current = head;
    while (current)
    {
        current = current->next;
        count++;
    }
    cout << "Total number of tasks in the To-Do List: " << count << "." << endl;
}

// Function to delete a task from the beginning of the list
void delete_Beg(TaskList *&head)
{
    TaskList *temp = head;
    head = head->next;
    free(temp);
}

// Function to delete a task from the end of the list
void delete_End(TaskList *&head)
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
        TaskList *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = nullptr;
    }
}

// Function to delete a task based on its task number
void delete_by_val(TaskList *&head, int num)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
    }
    else if (head->task_num == num)
    {
        TaskList *temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        TaskList *temp = head;
        while (temp->next && temp->next->task_num != num)
        {
            temp = temp->next;
        }
        if (temp->next)
        {
            TaskList *del = temp->next;
            temp->next = temp->next->next;
            free(del);
        }
        else
        {
            cout << "Task with specified number not found." << endl;
        }
    }
}

// Function to delete a task based on its position
void delete_by_pos(TaskList *&head, int pos)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
    }
    else if (pos == 0)
    {
        TaskList *temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        TaskList *temp = head;
        for (int i = 1; i < pos && temp->next; i++)
        {
            temp = temp->next;
        }
        if (temp->next)
        {
            TaskList *del = temp->next;
            temp->next = temp->next->next;
            free(del);
        }
        else
        {
            cout << "Position is out of range." << endl;
        }
    }
}

// Function to search for a task based on its description
void search_byval(TaskList *&head, const string &desc)
{
    int count = 1;
    TaskList *temp = head;
    while (temp != nullptr && temp->taskDescription != desc)
    {
        count++;
        temp = temp->next;
    }

    if (temp != nullptr)
    {
        cout << "Search Result: Task \"" << desc << "\" found at position " << count << " in the list." << endl;
    }
    else
    {
        cout << "Search Result: Task \"" << desc << "\" not found in the list." << endl;
    }
}
