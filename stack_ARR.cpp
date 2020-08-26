#include <iostream>
#include <stdio.h>

using namespace std;

#define MAX 10

template <class T>

class Stack
{
	T arr[MAX];

 public:

     T item,r;
     int top;

     Stack()
     {
     	top=-1;
     }

     void push(T a)
     {
     	if(top==MAX)
     		cout<<"\nStack is full";
     	else
     	    arr[++top] = a;
     }

     T pop()
     {
     	if(top==-1)
     	{
     		cout<<"\nStack is empty";

     	}
     	else
     		return arr[top--];
     }
     void display()
     {cout<<"displaying";
              for( int i =0;i<top;i++)
            cout<<arr[i];

     }

     void Clear()
     {
         while(top!=-1)
         {
         	cout<<arr[top--]<<"->";
         }



     }
};


int main()
{
    Stack <int>s;
    int n;
    int k;
    int ch;
    while(1)
    {
    	cout<<"\n enter your choice";
    	cin>>ch;
    	switch(ch)
    	{
          case 1:
                  cout<<"\nEnter the value to be pushed : ";
                  cin>>n;
                  s.push(n);
                  break;
          case 2:
                  k = s.pop();
                  cout<<"\nValue popped out is : "<<k;
                  break;
          //case 3:
            //      s.Clear();
              //     break;
          case 3:
            s.display();
            break;

          default:
                  cout<<"\nEnter a valid choice";
    	}
    }
	return 0;
}
