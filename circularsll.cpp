#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*last,*temp;

class circular_llist
{
    public:
        void create_node();
        void add_begin(int v);
        void add_after(int v, int p);
        void delete_element(int v);
        void search_element(int v);
        void display_list();
        void delet_beg();
        void delet_last();
        circular_llist()
        {
            last = NULL;
        }
};


void circular_llist::create_node()
{  char ch = 'y';
    int n;
    do
{
    cout<<"enter the element";
    cin>>n;
    temp = new node;
    temp->data = n;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
    cout<<"if you want to add more enter y else 0";
    cin>>ch;
} while(ch == 'y');
}


void circular_llist::add_begin(int value)
{
    if (last == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }

    temp = new node;
    temp->data = value;
    temp->next = last->next;
    last->next = temp;
}


void circular_llist::add_after(int value, int pos)
{
    if (last == NULL)
    {
        cout<<"no list present"<<endl;
        return;
    }
    struct node *n;
    n = last->next;
    for (int i = 0;i < pos-1;i++)
    {
        n = n->next;

    }
    temp = new node;
    temp->data = value;
    temp->next = n->next;

    n->next = temp;


}


void circular_llist::delete_element(int value)
{
    struct node *temp, *n;
    n = last->next;


    if (n->data == value)
    {
        temp = n;
        last->next = n->next;
        free(temp);
        return;
    }
    while (n->next != last)
    {
             if (n->next->data == value)
        {
            temp = n->next;
            n->next = temp->next;
            free(temp);

            return;
        }
        n = n->next;
    }
    cout<<"\n element not pres.";
}


void circular_llist::search_element(int value)
{
    struct node *n;
    int c = 0;
    n = last->next;
    while (n != last)
    {
        c++;
        if (n->data == value)
        {
            cout<<"Element "<<value;
            cout<<" at"<<c<<endl;
            return;
        }
        n = n->next;
    }
    if (n->data == value)
    {
        c++;
        cout<<"Element "<<value;
        cout<<" found at position "<<c<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found in the list"<<endl;
}

void circular_llist ::delet_beg()
{ temp = last->next;
  last->next = temp->next;
  free(temp);
}

void circular_llist :: delet_last()
{

    temp = last->next;
    while(temp->next != last)
    {
        temp = temp->next;

    }
    node *s;
    s = temp->next;
    temp->next = last->next;
    free(s);
    last = temp;


}
void circular_llist::display_list()
{
    temp = last->next;
    if (last == NULL)
    {
        cout<<"List empty"<<endl;
        return;
    }


    while (temp != last)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}


int main()
{
    int ch, n, p;
    circular_llist cl;
    while (1)
    {

        cout<<"enter your choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:

            cl.create_node();
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the element: ";
            cin>>n;
            cl.add_begin(n);
            cout<<endl;
            break;
        case 3:
            cout<<"Enter the element: ";
            cin>>n;
            cout<<"Insert element after position: ";
            cin>>p;
            cl.add_after(n, p);
            cout<<endl;
            break;
        case 4:

            cout<<"entr the element for deletion: ";
            cin>>p;
            cl.delete_element(p);
            cout<<endl;
            break;
        case 5:

            cout<<"enter element to search ";
            cin>>n;
            cl.search_element(n);
            cout<<endl;
            break;
        case 6:
            cl.display_list();
            break;
        case 7:
            cl.delet_beg();
        case 8:
            cl.delet_last();

        }
    }
    return 0;
}

