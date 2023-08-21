#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* add_at_the_end(node* ptr , int data);

int main(){
    node* mylist=new node;
    mylist->data=45;
    mylist->next=NULL;
    node* ptr=mylist;
    ptr=add_at_the_end(ptr,34);
    ptr=add_at_the_end(ptr,85);
    ptr=mylist;
    while(ptr){
        cout<< ptr->data<< " ";
        ptr=ptr->next;
    }
    cout << endl;
    return 0;
}
node* add_at_the_end(node* ptr , int data){
    node* temp= new node;
    temp-> data= data;
    temp->next =NULL;
    ptr->next=temp;
    return temp;
}