#include<iostream>
#include<stdio.h>

using namespace std;

template <class t>
class node
{
	public:
		t data;
		node<t> *prev;
		node<t> *next;
};

template <class t>
class DLL
{
	public:
		node<t> *first,*last,*temp,*temp1;
		DLL()
		{
			first=last=NULL;
		}
		~DLL()
		{
			temp=first;
			while(first!=NULL)
			{
				temp=temp->next;
				delete first;
				first=temp;
			}
		}
		void insertAtBeg(t);
		void insertAtEnd(t);
		void insertInBet(t);
		void delAtEnd();
		void delAtBeg();
		void delInBet();
		int search(t);
		void reverse();
		void display();
};

template <class t>
void DLL<t>::insertAtBeg(t el)
{
	temp=new node<t>;
	temp->next=temp->prev=NULL;
	temp->data=el;
	if(first==NULL)
	{
		first=last=temp;
	}
	else
	{
		temp->next=first;
		first->prev=temp;
		first=temp;
	}
}

template <class t>
void DLL<t>::insertAtEnd(t el)
{
	temp=new node<t>;
	temp->next=temp->prev=NULL;
	temp->data=el;
	if(first==NULL)
	{
		first=last=temp;
	}
	else
	{
		last->next=temp;
		temp->prev=last;
		last=temp;
	}
}

template <class t>
void DLL<t>::insertInBet(t el)
{
	temp=new node<t>;
	temp->next=temp->prev=NULL;
	temp->data=el;
	int pos;
	cout<<"\n Enter the position for the node : ";
	cin>>pos;
	if(first==NULL)
	{
		first=last=temp;
	}
	else
	{
		temp1=first;
		for(int i=1;i<pos-1;i++)
		{
			temp1=temp1->next;
			if(temp1==last&&i==(pos-2))
			{
				last->next=temp;
				temp->prev=last;
				last=temp;
				break;
			}
			if(temp1==NULL)
			{
				cout<<"\n no such position found!!!";
			//	exit(0);
			}
		}
		temp->next=temp1->next;
		temp1->next->prev=temp;
		temp->prev=temp1;
		temp1->next=temp;
	}
}

template <class t>
void DLL<t>::delAtBeg()
{
	temp=first;
	first=first->next;
	first->prev=NULL;
	delete temp;
}

template <class t>
void DLL<t>::delAtEnd()
{
	temp=last;
	last=last->prev;
	delete temp;
	last->next=NULL;
}

template <class t>
void DLL<t>::delInBet()
{
	int pos;
	cout<<"\n Enter the position of the node : ";
	cin>>pos;
	temp1=first;
	for(int i=1;i<pos-1;i++)
	{
		temp1=temp1->next;
	}
	temp=temp1->next;
	temp1->next=temp1->next->next;
	delete temp;
}

template <class t>
int DLL<t>::search(t el)
{
	temp=first;
	while(temp!=NULL)
	{
		if(temp->data==el)
		    return 1;  
		temp=temp->next;	  
	}
	return 0;
}

template <class t>
void DLL<t>::reverse()
{
	temp1=last;
	temp=first;
	while(temp!=temp1)
	{
		while(temp->next!=temp1)
		{
			temp=temp->next;
		}
		temp1->next=temp;
		temp1=temp;
		temp=first;
	}
	temp=first;
	first=last;
	last=temp;
	last->next=NULL;
}

template <class t>
void DLL<t>::display()
{
	temp=first;
	while(temp!=NULL)
	{
		cout<<" "<<temp->data;
		temp=temp->next;
	}
}

int main()
{
	int ch,ch1,flag=0;
	int e;
	char ce;
	float fe;
	
	cout<<"\n 1. int";
	cout<<"\n 2. char";
	cout<<"\n 3. float";
	cout<<"\n Enter your choice(default is 3) : ";
	cin>>ch1;
	if(ch1==1)
	{
		DLL<int> ob;
		do
		{
			
			cout<<"\n 1. Insert in begining";
			cout<<"\n 2. Insert at end";
			cout<<"\n 3. Insert in between";
			cout<<"\n 4. Delete in begining";
			cout<<"\n 5. Delete at end";
			cout<<"\n 6. Delete in between";
			cout<<"\n 7. Search";
			cout<<"\n 8. Reverse";
			cout<<"\n 9. Display";
			cout<<"\n Enter your choice(0 to exit) : ";
			cin>>ch;
			
			switch(ch)
			{
				case 1: cout<<"\n Enter the data : ";
				        cin>>e;
				        ob.insertAtBeg(e);
				        break;
				case 2: cout<<"\n Enter the data : ";
				        cin>>e;
				        ob.insertAtEnd(e);
				        break;
				case 3: cout<<"\n Enter the data : ";
				        cin>>e;
				        ob.insertInBet(e);
				        break;
				case 4: ob.delAtBeg();
				        break;
				case 5: ob.delAtEnd();
				        break;
				case 6: ob.delInBet();
				        break;	
				case 7: cout<<"\n Enter the element to be searched : ";
				        cin>>e;
				        flag=ob.search(e);
				        if(flag==1)
				              cout<<"\n Element found !";
				        else
						      cout<<"\n NOT foind !!!";      
				        break;
				case 8: ob.reverse();
				        break;	
				case 9: ob.display();
				        break;
		//		case 0: exit(0);
				//default: "\n Wrong choice !!!";
				        // break;														        
			}
		}while(ch!=0);
	}
	else if(ch1==2)
	{
		DLL<char> ob;
		do
		{

			cout<<"\n 1. Insert in begining";
			cout<<"\n 2. Insert at end";
			cout<<"\n 3. Insert in between";
			cout<<"\n 4. Delete in begining";
			cout<<"\n 5. Delete at end";
			cout<<"\n 6. Delete in between";
			cout<<"\n 7. Search";
			cout<<"\n 8. Reverse";
			cout<<"\n 9. Display";
			cout<<"\n Enter your choice(0 to exit) : ";
			cin>>ch;
			
			switch(ch)
			{
				case 1: cout<<"\n Enter the data : ";
				        cin>>ce;
				        ob.insertAtBeg(ce);
				        break;
				case 2: cout<<"\n Enter the data : ";
				        cin>>ce;
				        ob.insertAtEnd(ce);
				        break;
				case 3: cout<<"\n Enter the data : ";
				        cin>>ce;
				        ob.insertInBet(ce);
				        break;
				case 4: ob.delAtBeg();
				        break;
				case 5: ob.delAtEnd();
				        break;
				case 6: ob.delInBet();
				        break;	
				case 7: cout<<"\n Enter the element to be searched : ";
				        cin>>ce;
	    		        flag=ob.search(ce);
				        if(flag==1)
				              cout<<"\n Element found !";
				        else
						      cout<<"\n NOT foind !!!";      
				        break;
				case 8: ob.reverse();
				        break;	
				case 9: ob.display();
				        break;
				//case 0: exit(0);
				//default: "\n Wrong choice !!!";
				      //   break;														        
			}
		}while(ch!=0);
	}
	
	else
	{
		DLL<float> ob;
		do
		{

			cout<<"\n 1. Insert in begining";
			cout<<"\n 2. Insert at end";
			cout<<"\n 3. Insert in between";
			cout<<"\n 4. Delete in begining";
			cout<<"\n 5. Delete at end";
			cout<<"\n 6. Delete in between";
			cout<<"\n 7. Search";
			cout<<"\n 8. Reverse";
			cout<<"\n 9. Display";
			cout<<"\n Enter your choice(0 to exit) : ";
			cin>>ch;
			
			switch(ch)
			{
				case 1: cout<<"\n Enter the data : ";
				        cin>>fe;
				        ob.insertAtBeg(fe);
				        break;
				case 2: cout<<"\n Enter the data : ";
				        cin>>fe;
				        ob.insertAtEnd(fe);
				        break;
				case 3: cout<<"\n Enter the data : ";
				        cin>>fe;
				        ob.insertInBet(fe);
				        break;
				case 4: ob.delAtBeg();
				        break;
				case 5: ob.delAtEnd();
				        break;
				case 6: ob.delInBet();
				        break;	
				case 7: cout<<"\n Enter the element to be searched : ";
				        cin>>fe;
				        flag=ob.search(fe);
				        if(flag==1)
				              cout<<"\n Element found !";
				        else
						      cout<<"\n NOT foind !!!";      
				        break;
				case 8: ob.reverse();
				        break;	
				case 9: ob.display();
				        break;
			//	case 0: exit(0);
			//	default: "\n Wrong choice !!!";
				       //  break;														        
			}
		}while(ch!=0);
	}
	return 0;
}
