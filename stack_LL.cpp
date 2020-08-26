#include <iostream>
#include <stdio.h>
using namespace std;


class Stack
{


struct node
{
    int data;
    node* next;

}*top,*temp;
public:
    Stack()
    {
        top = NULL;
    }
    void push();
    void pop();
    void Clear();
    void isempty();
    void display();


};

void Stack :: push()
{

    int val;
    cout<<"\n enter the no. ";
    cin>>val;
    temp = new node;
    temp->data = val;
    temp->next = NULL;
    if(top == NULL)
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;


    }
    return;
}
void Stack :: pop()
{
 if(top == NULL)
 {
     cout<<"\n list is empty;";

 }
 else
 {
     cout<<"no. to be deleted is:"<<top->data;
     temp = top;
     top = top->next;
     delete temp;
 }
}
void Stack :: Clear()
{   node* temp1;
    temp = top;
    while(temp != NULL)
    {
        cout<<temp->data<<"deleted"<<endl;
        temp1 = temp->next;
        delete temp;
        temp = temp1;

    }
    top = NULL;

}
void Stack :: display()
{
    temp = top;
    while(temp != NULL)
    {
        cout<<temp->data;
        temp = temp->next;

    }
}
int main()
{
    Stack s;
    int ch;

    while(1)
    {
     cout<<"\n enter your choice";
    cin>>ch;



    switch(ch)
    {
    case 1:
        s.push();
        break;
    case 2:
        s.pop();
        break;
    case 3:
        s.Clear();
        break;
    case 4:
        s.display();
        break;
    default:
        cout<<"\n wrong choice";
    }
    }

    return 0;
}

