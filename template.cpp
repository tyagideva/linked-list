#include<iostream>
using namespace std;
template <class X>
class Node
{
	public:
    X info;
    Node *next;
    Node(X data)
    {
        info = data;
        next = NULL;
    }
};
template <class T>
class linkedList
{
    Node <T> *head, *tail ;

public :
    linkedList()
    {
        head = tail = NULL ;
    }
    void add_at_head(T data)
    {
    if( head == NULL )
        head = tail = new Node<T>(data);
    else
    {
        Node <T> *p = new Node<T>(data);
        p->next = head;
        head = p;
    }       
    }
    void add_at_tail(T data)
    {
        if( tail == NULL )
            head = tail = new Node<T>(data);

        else
        {
            Node <T> *p = new Node<T>(data);
            tail = tail->next = p;
        }    
    }
    bool traverse()
    {
        if( head == NULL ) 
		 return false;
        else
        {
            cout <<"\npresent list is :\n";
            Node <T> *p = head;
            while( p != NULL )
            {
                std::cout << p->info << ' ';
                p = p->next;
            }
            return true;
        }        
    }
    int search(T element)
    {
        if( head == NULL )  
		return -2;
        Node <T> *p = head;
        while( p!= NULL && p->info!=element )   
		p = p->next;
        return ( p == NULL )? -1 : 0 ;        
    }
    int count_nodes()
    {
        if( head == NULL )  
		return 0;
        int count = 0;
        Node <T> *p =head;
        while( p!=NULL && count++ )    
		p = p->next;
        return count;
    }
    bool delete_from_head()
    {
        if( head == NULL )  
		return false;
        else if( head == tail )
        {
            delete(head);
            head = tail = NULL;
            return true;
        }
        else
        {
            Node <T> *p =head;
            head = head->next;
            delete(p);
            return true;        
        }
    }
    bool delete_from_tail()
    {
        if( tail == NULL )  
		return false;
        else if( head == tail )
        {
            delete(head);
            head = tail = NULL;
            return true;
        }
        else
        {
            Node <T> *p = head;

            while( p->next->next != NULL )  p = p->next;

            tail = p;
            p = p->next;
            tail->next = NULL;
            delete(p);

            return true;
        }
    }

    bool reverse_list()
    {
        if( head == NULL)   return false;
        Node <T> *prev = NULL;
        Node <T> *current = head;
        Node <T> *next = NULL;

        while( current != NULL )
        {
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return true;
    }
};
void printerror(string str="\nInvalid input, enter again :")
{
    cin.clear();
    cin.ignore(100,'\n');
    cout << str ;
}
template <class T>
void operations()
{
    linkedList <T> list;
    int choice;
    T data;
  while(1)
  {
    cout << "\t1. insert at Head\n";
    cout << "\t2. insert at tail\n";
    cout << "\t3. Print the list\n";
    cout << "\t4. Search an element\n";
    cout << "\t5. Print total elements\n";
    cout << "\t6. Delete from head\n";
    cout << "\t7. Delete from end\n";
    cout << "\t8. Reverse the list\n";
    cout << "\t9. EXIT";
    cout << "\nEnter your choice :";
    while( !(cin>>choice) || choice<=0 || choice>9 ) 
	printerror("Invalid choice, enter again :");

    switch(choice)
    {
        case 1:
            cout << "\nEnter the data :";
            while( !(cin>>data) )   
			printerror("Not a valid data :");
            list.add_at_head(data);
            cout << "\nDone!\n";
            break;

        case 2:
            cout << "\nEnter the data :";
            while( !(cin>>data) )  
			 printerror("Not a valid data for your list :");

            list.add_at_tail(data);
            cout << "\nDone\n";
            break;

        case 3:
            if( list.traverse() ); 
            else
                cout << "\nlist is Empty!";
            break;

        case 4:
            T element;
            cout << "\nEnter the element to search for :";
            while( !(cin>>element) )   printerror("invalid element, enter again :");
            int stat;
            stat = list.search(element);

            if( stat == -2 )
                cout << "\nlist is empty!\n";
            else
            {
                cout << "\nelement " << element << " is ";
                if( stat == -1 )  cout << "NOT ";
                cout << "present in the list.\n";
            }
            break;

        case 5:
            cout << "\nThere are" << list.count_nodes() << "nodes in the list.\n";
            break;

        case 6:
        if( list.delete_from_head() )
            cout << "\nSuccessful!\n";
        else
            cout << "\nlist is empty!\n";            
        break;

        case 7:
        if( list.delete_from_tail() )
            cout << "\nSuccessfull!";
        else
            cout << "\nFailed, list is empty!";
        break;

        case 8:
        if( list.reverse_list() )
        {
            cout << "\nAfter reversing: ";
            list.traverse();
        }
        else
        {
            cout << "\nCurrent list empty\n";
        }
        break;            
        case 9:
        return;
    }
    cout << "\nPress enter to continue ...";
    cin.ignore(100,'\n');
    char ch = getchar();
    }
    return;
}
int main()
{
    int type;
    char ch;

 do{
 	cout<<"Enter choice : ";
    cout <<"\n1. LL of Integers";
    cout <<"\n2. LL of Characters";
    cout <<"\n3. LLof Floats";
    cout <<"\nEnter your choice :";
    while( !(cin>>type) || type <= 0 || type>3 )
    if( type == 1)          
		operations <int> ();   
    else if( type == 2)     
		operations <char>();   
    else                    
		operations <float>();
    cout << "\n\nTry diff type of LL? (y/n) :";
    while( !(cin>>ch) || ( tolower(ch)!='y' && tolower(ch)!='n' ) )
        printerror("enter 'y' or 'n' :");
  }
  while( tolower(ch) == 'y' ); 
    return 0;
}
