#include <iostream>
#include<conio.h>
#include<process.h>
using namespace std;
class poly
{

     struct node

    {int coff,exp;
     struct node* next;
    }

  *temp,*first,*last;

  public:
      poly()
      {
         first = NULL;
         last = NULL;
      }
      void get_poly();
      void add(poly pp , poly pp1);
      void show();

};
void poly :: get_poly()
{

    char ch = 'y';
    do
    {
        int c,e;
      temp = new node;
        cout<<"\n enter the coffecient ";
        cin>>c;
        cout<<"\n enter the exp.";
        cin>>e;
        temp->coff = c;
        temp->exp = e;
        temp->next = NULL;
        if(first == NULL)
        {

        first = temp;
        last = first;
        }
        else
        {  last->next = temp;
            last = temp;

        }
        cout<<"\n if you want to continue press y";
        cin>>ch;
    }    while(ch=='y');

}
void poly:: show()
{
    temp = first;
    while(temp!= NULL)
    {
        cout<<temp->coff<<"X^"<<temp->exp<<"+";
        temp = temp->next;
    }
}
void poly:: add(poly pp,poly pp1)

{
    node * p,*p1;
    p = pp.first;
    p1 = pp1.first;
    cout<<p1->next;
 while(p->next && p1->next)
 { temp = new node;
    if(p->exp > p1->exp)
    {
        temp->exp = p->exp;
        temp->coff = p->coff;
        p =  p->next;
    }
    else if(p1->exp > p->exp)
    {
        temp->exp = p1->exp;
        temp->coff = p1->coff;
        p1 =  p1->next;
    }
    else
    {
        temp->exp = p->exp;
        temp->coff = p1->coff + p->coff;
        p1 =  p1->next;
        p1 =  p1->next;
    }
    if(first == NULL)
       {

        first = temp;
        last = NULL;}

    else
    {
        last->next = temp;
        last = temp;

    }
 }

 }

 int main()
 {

     poly p1,p2,p3;
     p1.get_poly();
     p1.show();
     p2.get_poly();
     p2.show();
     p3.add(p1,p2);
     p3.show();
return 0;
 }





