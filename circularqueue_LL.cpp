#include <iostream>
#include<stdio.h>

using namespace std;
class stack
{
    struct node
    {
        node* next;
        int data;
    }*first,*last,*temp;
public:
 stack()
 {
     first = NULL;
     last = NULL;
 }
 void push();
 void pop();
 void clear();
 void display();

};
void stack:: push()
{
   int a;
   cout<<"\n enter the no.to be pushed";
   cin>>a;
   temp = new node;
   temp->data = a;
   temp->next = NULL;
   if(first == NULL)
   {
     first = temp;
     last = temp;
     last->next = NULL;
   }
   else
   {
       last->next = temp;
       last = temp;
       //temp->next = NULL;
   }}
   void stack:: pop()
   {
       if(first == NULL)
        cout<<"\n list is empty";
       else
       {
           cout<<"\n poped item is"<<first->data;
            temp = first;
           first = first->next;
           delete temp;

       }
   }
   void stack :: clear()
   {
       temp = first;
       while(temp!= NULL)

       {

        cout<<temp->data<<" ";
       node *temp1 =temp;
       temp = temp->next;
       delete(temp1);
       }
       cout<<"\n null";
       first = NULL;
       last = NULL;


   }
   void stack ::display()
   {
       temp = first;
       while(temp!= NULL)
       {
           cout<<temp->data<<" ";
           temp = temp->next;
       }
   }


int main()
{
        stack s;
    int ch;
    while(1)
    {
    	cout<<"\n1.PUSH\n2.POP\n3.CLEAR\n 4.display";
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
                  s.clear();
                  break;
                  case 4:
                      s.display();
                      break;
          default:
                  cout<<"\nEnter a valid choice";

}}
return 0;
}
