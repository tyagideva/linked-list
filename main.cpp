#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;



class List
{
    struct node
    {int data;
     struct node* next;
     struct node* pre;
}

     *temp,*first;
public:
    List()
    {
        first=NULL;
       // last=NULL;
    }
    void create();
    void  delet_bet(int n);
    void del_big();
    void display();
    void insert_end();
    void Insert_bet(int data, int n);
    void delet_last();
    void insert_at_beg();
    void Search(int n);
    void Reverse();
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
    temp->pre = NULL;
    if(first==NULL)
    {
        first=temp;
       // last=first;
    }


    else
    {

       node *s;

        s = first;
        while(s->next != NULL)
        {
            s = s-> next;

        }
        s->next = temp;
        temp-> pre = s;
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
   temp->pre = NULL;
   if (n == 1){
    temp->next = first;
    first->pre = temp;
    first = temp;
    return;
   }
    node *temp2 ;
   temp2 = first;
   for (int i = 0; i < n-2; i++){// i feel like it doesn't even go through this loop
     temp2 = temp2->next;
   }
   temp->next = temp2->next;
   temp2->next->pre = temp;
   temp->pre = temp2;
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

    node *a;
    a = first;
    while(a->next != NULL)
    {
        a = a->next;

    }
    a->next = temp;
    temp->pre = a;

}
void List :: delet_bet(int n)
{ node *q;
    temp = first;


while (temp->next->next != NULL)
    {
        /*Element deleted in between*/
        if (temp->next->data == n)
        {
            q = temp->next;
            temp->next = q->next;
            q->next->pre = temp;
            cout<<"Element Deleted"<<endl;
            free(q);
            return;
        }
        temp = temp->next;
    }
}

void List:: insert_at_beg()
{    int n;
    temp = new node;
    cout<<"\n enter the element to be entered";
    cin>>n;
    temp->data = n;
    temp->pre = NULL;
    temp->next = first;
    first->pre = temp;
    first = temp;




}
void List:: delet_last()
{    temp = first;
   node *temp1;
while(temp->next->next != NULL)
 temp = temp->next;

temp1 = temp->next;

delete(temp1);
temp->next = NULL;




}
void List::display()
 {
    temp = new node;
     temp = first;
    while(temp != NULL)
    {
        cout<<temp->data;
        cout<<"-->";
        temp = temp->next;
    }


    cout<<"NULL";
}
void List:: del_big()
{   temp = new node;
    temp = first;
    first = first->next;
    first->pre = NULL;
    delete(temp);



}
void List ::Reverse()
{
    node *p1, *p2;
    p1 = first;
    p2 = p1->next;
    p1->next = NULL;
    p1->pre = p2;
    while (p2 != NULL)
    {
        p2->pre = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->pre;
    }
    first = p1;
}



/*void List :: Search(int n)
{ int a = 0;
temp = new node;
  temp = first;
  while(temp->next != NULL)
  {
      a++;
      if(temp->data == n)
      {

       cout<<"\n element present at"<<a;
      //return;
      //break;
      }
      temp = temp->next;

  }
  cout<<"\n element not found";


}
*/
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
       // case 9:
         //   l.Search(5);
        case 10:
            l.Reverse();

        }
    }
    return 0;
}
