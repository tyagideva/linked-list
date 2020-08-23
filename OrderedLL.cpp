#include<iostream>
#include<stdio.h>
using namespace std;
class OLL
{
	public:
	class node
	{
		public:
		int data;
		node *ptr;
	} 
	*head,*last,*temp,*temp1;
	OLL()
	{
		head=last=NULL;
	}
	void insert(int);
	void display();
	void deleteNode(int);
	void merge(OLL);
	~OLL();
};
void OLL::insert(int el)
{
	temp=new node;
	temp->data=el;
	temp->ptr=NULL;
	if(head==NULL)
	{
		head=last=temp;
	}
	else if(temp->data <= head->data)
	{
		temp->ptr=head;
		head=temp;
	}
	else if(temp->data >= last->data)
	{
		last->ptr=temp;
		last=temp;
	}
	else
	{
	temp1=head;
	while(temp1!=last)
	{
	if((temp->data > temp1->data) && (temp->data <= temp1->ptr->data))
	{
		temp->ptr=temp1->ptr;
		temp1->ptr=temp;
	}
	temp1=temp1->ptr;
	}
	}
}
void OLL::deleteNode(int n)
{
	temp=head;
	if(n==1)
	{
		temp=head;
		head=head->ptr;
		delete temp;
	}
	else  {
	for(int i=1;i<n-1;i++)
	{
		temp=temp->ptr;
	}
	temp1=temp->ptr;
	temp->ptr=temp1->ptr;
	delete temp1;
	cout<<"\nNode Deleted";
   }
}
void OLL::display()
{
	temp=head;
	cout<<"\nLinked List: ";
	while(temp!=NULL)
	{
		cout<<" "<<temp->data;
		temp=temp->ptr;
	}
}
void OLL::merge(OLL ob)
{
	ob.temp=ob.head;
	while(ob.temp!=NULL)
	{
		insert(ob.temp->data);
		ob.temp=ob.temp->ptr;
	}	
}
OLL::~OLL()
{
temp=head;
while(head!=NULL)
{
	temp=temp->ptr;
	delete head;
	head=temp;
}
}
int main()
{
	int ch,el,n,i=1;
	OLL ob1,ob2;
	
	do
	{
	    cout<<"1.insert an element : ";
	    cout<<"\n2.delete an element : ";
	    cout<<"\n3.merge two ll : ";
	    cout<<"\n4.display";
	    cout<<"\nEnter you choice: ";
	    cin>>ch;
	    switch(ch)
	    {
	    	case 1:
    		cout<<"\nEnter the element: ";
    		cin>>el;
    		ob1.insert(el);
    		break;
	    	case 2:
		    cout<<"\nEnter the position to delete: ";
			cin>>n;
			ob1.deleteNode(n);
			break;
			case 3:
		    cout<<"\nEnter the no. of nodes in list: ";
			cin>>n;
			while(n>0)
			{
				cout<<"\nEnter the element no. "<<i<<": ";
				cin>>el;
				ob2.insert(el);
				i++;
				n--;
			}		
			ob1.merge(ob2);
			break;
			case 4:
		    ob1.display();
			break;
			default:
			break;		
		}
	}while(ch!=0);
	return 0;
}
