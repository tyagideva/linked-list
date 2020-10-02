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
        cout<<"Found";
        cout<<endl;
    else
        cout<<"NOt Fount";
cout<<endl;
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

    }

    }while(ch!= 0);
    return 0;


}


