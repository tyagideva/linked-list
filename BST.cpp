#include <iostream>
#include<stdio.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

};
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
    int ch,n,e;
    do
    {
        cout<<"---------MAIN MENU--------";
        cout<<"\n 1 Insertion";
        cout<<"\n 2 postorder,inorder, preorder";
        cout<<"\n 3 to search for an element";
        cout<<"\n 4 to find no. of leaf and non leaf";
        cout<<"\n 5 to find the height of the tree";
        cout<<"\n 6 to find preorder traversal iterative";
        cout<<"\n 7 to find postorder traversal iterative";
        cout<<"\n 8 to find inorder traversal iterative";
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
    case 6:
        ob.ite_preorder(ob.root);

    case 7:
        ob.ite_postorder(ob.root);
    case 8:
        ob.ite_inorder(ob.root);
    }

    }while(ch!= 0);
    return 0;


}


