#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;



class List
{
    struct node
    {int data;
     struct node* next;
}

     *temp,*first,*last;
public:
    List()
    {
        first=NULL;
        last=NULL;
    }
    void create();


    void display();

};
void List::create()
{  char ch ='y';
    do{
    temp=new node;
    int n;
    cout<<"\nEnter an Element:";
    cin>>n;
    temp->data=n;
    temp->next=NULL;
    if(first==NULL)
    {
        first=temp;
        last=first;
    }

    else
    {
        last->next=temp;
        last=temp;
    }
    cout<<"if you want to add more enter y else 0";
    cin>>ch;
}while(ch == 'y');
}
void List::display()
{
    temp=first;
    if(temp==NULL)
    {
        cout<<"\nList is Empty";
    }
    while(temp!=NULL)
    {
        cout<<temp->data;
        cout<<"-->";
        temp=temp->next;
    }
    cout<<"NULL";
}

int main()
{
    List l;
    int c;
    while(1)
    {

        cout<<"\nEnter Your Choice:";
        cin>>c;
        switch(c)
        {
        case 1:
            l.create();
            break;
        case 2:
            l.display();
            break;

        }
    }
    return 0;
}
