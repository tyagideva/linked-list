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
    void  delet_bet(int n);
    void del_big();
    void display();
    void insert_end();
    void Insert_bet(int data, int n);
    void delet_last();
    void insert_at_beg();
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

void List:: Insert_bet(int data, int n)
{
   temp = new node;
   temp->data = data;
   temp->next = NULL;
   if (n == 1){
    temp->next = first;
    first = temp;
    return;
   }
   node* temp2 ;
   temp2 = first;
   for (int i = 0; i < n-2; i++){// i feel like it doesn't even go through this loop
     temp2 = temp2->next;
   }
   temp->next = temp2->next;
   temp2->next = temp;

}
void List :: insert_end()
{
    temp = new node;
    int n;
    cout<<"\nEnter an Element:";
    cin>>n;
    temp->data=n;
    temp->next=NULL;
    last->next=temp;
    last=temp;
}
void List:: delet_bet(int n)
{
   //temp = new node;
   //temp->data = data;
   //temp->next = NULL;
   //if (n == 1){
    //temp->next = first;
    //first = temp;
    //return;
   ///}

   temp = first;
   for (int i = 0; i < n-2; i++){// i feel like it doesn't even go through this loop
     temp = temp->next;
   }
   temp->next = temp->next->next;
   //temp2->next = temp;

}

void List:: insert_at_beg()
{    int n;
    temp = new node;
    cout<<"\n enter the element to be entered";
    cin>>n;
    temp->data = n;
    temp->next = first;
    first = temp;
}
void List:: delet_last()
{    int n = 0;
     temp = new node;
    temp = first;
   while(temp->next->next != NULL){
     n++;

     temp = temp->next;
   }
   delete(temp->next);
   temp->next = NULL;
   last = temp;

   //cout<<n;
   //node *temp1;
   //temp1 = new node;
   //temp1 = first;
   //for(int i= 0;i<n-1;n++)
   //{
    //   temp1 = temp1->next;
   //}
   //last = temp1;

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
void List:: del_big()
{
    first = first->next;


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
        l.insert_end();
        case 3:
            l.display();
            break;
        case 4:
            l.insert_at_beg();
        case 5:
            l.Insert_bet(0,3);
        case 6:
            l.del_big();
        case 7:
            l.delet_bet(3);
        case 8:
            l.delet_last();
        }
    }
    return 0;
}
