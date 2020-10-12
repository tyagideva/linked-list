#include <iostream>
#include<stdio.h>
using namespace std;
const int size = 10;
class node
{
public:
    int data;
    node *left;
    node *right;

};
class queue
{
    node *a[size],*n;
    int front , last;
public:
    queue()
    {
        front = last = -1;
    }
    void  enqueue(node *);
    node * dequeue();
    int isfull();
    int isempty();

};
int queue ::isempty()
{
    return (front==-1&&last==-1);}

int queue  :: isfull()
{
    //if((front == 0 && last = size-1) || (front = last+1) )
      //  return 1;
    //else
      //  return 0;
      return((front==0&&last==size-1)||front==last+1);
}
void queue :: enqueue(node *t)
{
    if(isfull())
	{ cout<<"\n\tCannot Insert";}
  else if(last==-1)
	  {  front=last=0;}
  else if(last==size-1&&front>0)
	  { last=0;}
  else
	  { last++;}
		 a[last]=t;

}
node * queue :: dequeue()
{
    if(isempty())
		 {cout<<"\n\tCannot delete";
		  n=0;}
  else
		{ n=a[front];
		  if(front==last)
			  {front=last=-1;}
		  else if(front==size-1)
				  {	front=0;  }
		  else
				 {front++;}
		}
  return n;
}

class stack
{
    node *a[10],*n;
    int top;
    public:
    stack()
    {
        top = -1;
    }
    void push(node *);
    node *pop();
    int isempty();
    int isfull();
    node * topp();


    };
    node * stack :: topp()
{


return a[top];
}
    void stack :: push(node * t)
    {
        if(isfull())
            cout<<"\n stack is full";
        else
        {
            top++;
            a[top]  = t;
        }

    }
    node * stack :: pop()
    {
        if(isempty())
            {cout<<"\n nothing to pop";
            n = 0;

            }

    else
    {
        n = a[top];
        top--;
    }
    return n;

    }
    int stack :: isfull()
    {
        if (top == 9)
            return 1;
        else
            return 0;

    }
    int stack :: isempty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }



class BST
{

public:
    node *temp,*temp2,*temp1,*root;
    int leaf,nonleaf;
    BST()
    {
        root = NULL;
        leaf = nonleaf = 0;
    }
    void insert();
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    void search(int ele);
    int height(node *t);
void leaf_nonleaf(node *t);
void ite_preorder(node *t);
void ite_postorder(node *t);
void ite_inorder(node *t);
void bsf_traversal(node *t);
void dcopy(node *& t);
void dmerg(node *& t);
void delcopy(node *t,int el);
void delmerg(node *t,int el);
int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
};
void BST :: insert()
{

    int i ;
    cout<<"\n Enter the node, 0 to end";
    cin>>i;
    while(i!= 0)
    {
        temp = new node;
        temp->data = i;
        temp->left = temp->right = NULL;
        if(root == NULL)
        {
            root = temp;
        }
        else
        {
            temp1 = root;
            while(temp1 != NULL)
            {
                if(i<temp1->data)
                {
                    temp2 = temp1;
                    temp1  = temp1->left;

                }
                else
                {
                    temp2 = temp1;
                    temp1 = temp1->right;
                }

            }
            if(i< temp2->data)
            {
                temp2->left = temp;
            }
            else
            {
                temp2->right =  temp;
            }

        }
        cout<<"\n Enter the node value ( 0 to exit ) : ";
	    cin>>i;

    }
}
void BST :: postorder(node *t)
{
    if(t != NULL)
    {
        postorder(t->left);
        postorder(t->right);
        cout<<" "<<t->data;
    }


}
void BST :: preorder(node *t)
{
    if(t != NULL)
    {   cout<<" "<<t->data;
        preorder(t->left);
        preorder(t->right);

    }


}
void BST :: inorder(node *t)
{
   if(t != NULL)
    {
        inorder(t->left);
        cout<<" "<<t->data;
        inorder(t->right);

    }
}
void BST:: ite_preorder(node *t)
{
    stack s1;
  if(t!= NULL)
    {
        s1.push(t);
        while(!s1.isempty())
        {
         t = s1.pop();

             cout<<" "<<t->data;
             if(t->right!= NULL)
             s1.push(t->right);
             if(t->left!= NULL)
             s1.push(t->left);

        }}


        }
        void BST :: ite_inorder(node *t)
        {stack s1;
            while(t!= NULL)
            {
                while(t != NULL)
                {
                    if(t->right !=NULL)
                    {
                        s1.push(t->right);
                    }
                    s1.push(t);
                    t = t->left;

                }
                t = s1.pop();
                while(!s1.isempty() && t->right == NULL)
                {
                    cout<<" "<<t->data;
                    t = s1.pop();
                }
                cout<<" "<<t->data;
                if(!s1.isempty())
                {
                    t = s1.pop();
                }
                else
                    t = NULL;
            }
        }
        void BST :: ite_postorder(node *t)
       {


        stack s1;
	node *temp1,*top;
	node * current;
	current = t;
	while((current!= NULL) || (!s1.isempty()))
    {
        if(current != NULL)
        {
            s1.push(current);
            current = current->left;

        }
        else
        {


        top = s1.topp();
        temp1 = top -> right;
        if(temp1 == NULL)
        {
            temp1 = s1.pop();
            cout<<" "<<temp1->data;
            while((!s1.isempty()) && (temp1 == s1.topp()->right))
            {
                temp1 = s1.pop();
                cout<<" "<<temp1->data;
            }
        }
        else{
            current = temp1;
        }



    }}
       }






void BST :: search(int ele)
{
    int f = 0;
    temp = root;
    while(temp)
    {
        if(ele == temp->data)
        {
            f = 1;
            break;

        }
        else if(ele> temp->data)
            temp = temp->right;
        else
            temp = temp->left;

    }
    if(f == 1)
        {cout<<"Found";
        cout<<endl;}
    else{
        cout<<"NOt Fount";
        cout<<endl;
}}
void BST :: bsf_traversal(node *temp)
{queue q1;
	if(temp!=0)
	 {
		 q1.enqueue(temp);
		 while(!q1.isempty())
		  {
			 temp=q1.dequeue();

			 cout<<" "<<temp->data;
			 if(temp->left!=0)
				{q1.enqueue(temp->left);}
			 if(temp->right!=0)
				 {q1.enqueue(temp->right);}
		  }
	 }
}
void BST :: leaf_nonleaf(node * t)
{

    if(t!= NULL)
    {


        if(t->left ==NULL && t->right == NULL)
        leaf++;
    else
        nonleaf++;
    leaf_nonleaf(t->left);
    leaf_nonleaf(t->right);
    }
}
void BST :: delcopy(node *t,int el)
{node* prev = NULL;
    while(t!= NULL)
    {
        if(t->data == el)
            break;
        prev = t;
        if( t->data < el)



            t = t->right;

        else



            t = t->left;

    }
        if(t!= NULL && t->data == el )
        {
            if(t == root)
                dcopy(root);
            else if(prev->left == t)
            dcopy(prev->left);
            else
                dcopy(prev->right);

        }
        else if(root!=0)
	  cout<<"\n\tKEY "<<el<<" IS NOT IN TREE";
	else
		cout<<"\n\tTREE IS EMPTY";
    }


void BST :: dcopy(node *& temp)
{node *prev,*tmp = temp;
    if(temp->left == NULL)
        temp = temp->right;
    else if(temp->right == NULL)
        temp = temp->left;
        else
        {tmp = temp->left;
        prev = temp;

            while(tmp->right !=NULL)
            {
                prev = tmp;
                tmp = tmp->right;
            }

            temp->data = tmp->data;
            if(prev == temp)
                prev->left = tmp->left;
            else
                prev->right = tmp->left;


        }
            delete tmp;

}
void BST :: delmerg(node *t,int el)
{node* prev = NULL;
    while(t!= NULL)
    {
        if(t->data == el)
            break;
        prev = t;
        if( t->data < el)



            t = t->right;

        else



            t = t->left;

    }
        if(t!= NULL && t->data == el )
        {
            if(t == root)
                dmerg(root);
            else if(prev->left == t)
            dmerg(prev->left);
            else
                dmerg(prev->right);

        }
        else if(root!=0)
	  cout<<"\n\tKEY "<<el<<" IS NOT IN TREE";
	else
		cout<<"\n\tTREE IS EMPTY";
    }
    void BST :: dmerg(node *& temp)
{node *tmp = temp;
    if(temp->left == NULL)
        temp = temp->right;
    else if(temp->right == NULL)
        temp = temp->left;
        else
        {tmp = temp->left;


            while(tmp->right !=NULL)
            {

                tmp = tmp->right;
            }

            tmp->right = temp->right;
            tmp = temp;
            temp = temp->left;

        }
            delete tmp;

}


int BST :: height(node *t)
{int lh,rh = 0;
    if(t == NULL)
        return 0;
    lh = height(t->left);
    rh = height(t->right);
    return 1+max(lh,rh);
}


int main()
{
    BST ob;
    int ch,n,e,al;
    do
    {
        cout<<"---------MAIN MENU--------";
        cout<<"\n 1 Insertion";
        cout<<"\n 2 recureive postorder,inorder, preorder";
        cout<<"\n 3 to search an element";
        cout<<"\n 4 to find leaf and non leaf";
        cout<<"\n 5 to find tree height";
        cout<<"\n 6 to find iterative preorder";
        cout<<"\n 7 to find iterative postorder";
        cout<<"\n 8 to find iterative inorder";
        cout<<"\n 9 to find bdf traversal";
        cout<<"\n 10 to do deletion by copying";
        cout<<"\n 11 to  do deletion by merging";
        cin>>ch;
    switch(ch)
    {
    case 1:
        ob.insert();
        break;

    case 2:
        cout<<"\n Inorder";
        ob.inorder(ob.root);
        cout<<"\n Preorder";
        ob.preorder(ob.root);
        cout<<"\n postorder";
        ob.postorder(ob.root);


        break;
    case 3:
        int ele;
        cout<<"\n enter the element to be searched";
        cin>>ele;
        ob.search(ele);
        break;
    case 4:
        ob.leaf_nonleaf(ob.root);
        cout<<"\n leaf = "<<ob.leaf;
    cout<<"\n Non leaf ="<<ob.nonleaf;
        break;
    case 5:
        int h;
        cout<<"\n height is";
        h = ob.height(ob.root);
        cout<<h;
        break;
    case 6:
        ob.ite_preorder(ob.root);
break;
    case 7:
        ob.ite_postorder(ob.root);
    break;
    case 8:
        ob.ite_inorder(ob.root);
        break;
        case 9:
        ob.bsf_traversal(ob.root);
        break;
        case 10:
            cout<<"enter the ele. to delete";
            cin>>al;
            ob.delcopy(ob.root,al);
            break;
        case 11:
            cout<<"enter the ele. to delete";
            cin>>al;

            ob.delmerg(ob.root,al);
    }

    }while(ch!= 0);
    return 0;


}


