#include <iostream>
#include <stdio.h>

using namespace std;

#define size 5

template <class T>

class queue
{
	T arr[size];

 public:

     T item,r;
     int first,last ;

     queue()
     {
     	first = last =-1;
     }

     void enqueue(int a);
     T dequeue();
     bool isfull()
     {
             return first == 0 && last == size -1 || first == last+1;
     }
     bool isempty()
     {
         if(first == -1)
            return true;
     }
    void Clear()
     {
         if(first == -1)
            cout<<"list is empty";
         else
         {
             for(int i = first ; i<=last;i++)


{





             cout<<"deleted ele is"<<arr[i];


         }
         cout<<"\n finished";}
         //else
           // cout<<"\n finished";
     }
     void show()
     {  int a = first;
     int b = last;

         for( int i = a ;i<=last;i++)
         {
             cout<<arr[i]<<" ";

         }
     }

};
template<class T>
void queue<T>::enqueue(int a)
{


if(!isfull())
	{
		if(last == size-1 || last == -1)
		{
			arr[0] = a;
			last = 0;

			if(first == -1)
				first = 0;
		}
		else
		{
			arr[++last] = a;
		}
	}
	else
		cout<<"\nQueue is Full";

      }


template<class T>
T queue<T> :: dequeue()

{
    T temp;
    temp = arr[first];
    if(first == last)
        first = last = -1;
    else if(first == size-1)
    first = 0;

        else
    first++;

    return temp;
}

int main()
{
    queue <int>s;
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
              cout<<s.first<<" "<<s.last;
                  cout<<"\nEnter the value to be pushed : ";
                  cin>>n;
                  s.enqueue(n);
                  break;
          case 2:
                cout<<s.first<<" "<<s.last;
                  k = s.dequeue();
                  cout<<"\nValue popped out is : "<<k;
                  break;
          case 4:
              cout<<s.first<<" "<<s.last;
                 s.Clear();
                break;
          case 3:
           cout<<s.first<<" "<<s.last;
            s.show();
            break;

          default:
                  cout<<"\nEnter a valid choice";
    	}
    }
	return 0;
}

