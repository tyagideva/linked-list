#include <iostream>
int n= 0;
using namespace std;
class heap
{public:
void max_heapify(int a[],int n);
void max_heap_insert(int a[],int key);
void heap_inc_key(int a[],int i,int key);
void heap_max(int a[]);
void extract_max(int a[]);
void build_max_heap(int a[]);
void show(int a[]);
};
void heap::build_max_heap(int a[])
{
    for(int i = n/2;i>0;i--)
    {
        max_heapify(a,i);
    }
}
void heap::extract_max(int a[])
{
    int max = a[1];
    a[1] = a[n];
    n = n-1;
    max_heapify(a,1);
    cout<<"Max is"<<max;
}
void heap:: heap_max(int a[])
{
    cout<<"Maximum element :"<<a[1];
}
void heap :: max_heapify(int a[],int i)
{int largest;
    int l = 2*i;
    int r = 2*i+1;

    if(l<=n&&a[l]>a[i])
    {largest = l;

    }
    else
        largest = i;
    if(r<=n&&a[r]>a[largest])
        largest = r;
    if (largest!=i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a,largest);
    }


}
void heap::max_heap_insert(int a[],int key)
{ int k = key;
    n = n+1;
    a[n] = -1;
    heap_inc_key(a,n,k);

}
void heap::heap_inc_key(int a[],int i,int key)
{
 if(a[i]>key)
 {
     cout<<"\n Error given key is smaller than the present value";
     //break;
     }

 a[i] = key;
 while(i>1&&a[i/2]<a[i])
 {
     int temp = a[i];
     a[i] = a[i/2];
     a[i/2] = temp;
     i = i/2;
     }
}
void heap::show(int a[])
{
    for (int i = 1;i<=n;i++)
    {
        cout<<" "<<a[i];
    }
}
int main()
{
heap h1;
int a[15];
    cout <<"Enter the size of heap";
    cin>>n;
    for(int i = 1;i<=n;i++)
        cin>>a[i];
        int ch ;
        do{
    cout<<"\nEnter your choice\n1: build_max_heaf\n2: max heapify\n3:heap insert\n4:increase max heap\n5:find maximum element\n6 extract maximum";
    cin>>ch;
    switch (ch)
    {


case 1:
    h1.build_max_heap(a);
    h1.show(a);
    break;

    case 2:
        int x;
        cout<<"\n Enter the location where you want to run max heapify";
        cin>>x;
    h1.max_heapify(a,x);
    h1.show(a);
    break;
    case 3:
        int k;
        cout<<"\n Enter the value you want to insert";
        cin>>k;
    h1.max_heap_insert(a,k);
    h1.show(a);
    break;
    case 4:
        int p,w;
        cout<<"\n Enter the location and key value you want to replace";
        cin>>w;
        cin>>p;
    h1.heap_inc_key(a,w,p);
    h1.show(a);
    break;
    case 5:
    h1.extract_max(a);
    h1.show(a);
    break;
        case 6:
    h1.heap_max(a);
    h1.show(a);
    break;
    }
    }while(ch!=0);

    return 0;
}
