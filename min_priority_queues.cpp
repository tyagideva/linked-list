#include <iostream>
int n= 0;
using namespace std;
class heap
{public:
void min_heapify(int a[],int n);
void min_heap_insert(int a[],int key);
void heap_dec_key(int a[],int i,int key);
void heap_min(int a[]);
void extract_min(int a[]);
void build_min_heap(int a[]);
void show(int a[]);
};
void heap::build_min_heap(int a[])
{
    for(int i = n/2;i>0;i--)
    {
        min_heapify(a,i);
    }
}
void heap::extract_min(int a[])
{
    int min = a[1];
    a[1] = a[n];
    n = n-1;
    min_heapify(a,1);
    cout<<"min is"<<min<<endl;
}
void heap:: heap_min(int a[])
{
    cout<<"minimum element :"<<a[1];
}
void heap :: min_heapify(int a[],int i)
{int smallest;
    int l = 2*i;
    int r = 2*i+1;

    if(l<=n&&a[l]<a[i])
    {smallest = l;

    }
    else
        smallest = i;
    if(r<=n&&a[r]<a[smallest])
        smallest = r;
    if (smallest!=i)
    {
        int temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
        min_heapify(a,smallest);
    }


}
void heap::min_heap_insert(int a[],int key)
{ int k = key;
    n = n+1;
    a[n] = -1;
    heap_dec_key(a,n,k);

}
void heap::heap_dec_key(int a[],int i,int key)
{
 if(a[i]<key)
 {
     cout<<"\n Error given key is greater than the present value";
     //break;
     }

 a[i] = key;
 while(i>1&&a[i/2]>a[i])
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
    cout<<"\nEnter your choice\n1: build_min_heaf\n2: min heapify\n3:heap insert\n4:increase min heap\n5:find minimum element\n6 extract minimum";
    cin>>ch;
    switch (ch)
    {


case 1:
    h1.build_min_heap(a);
    h1.show(a);
    break;

    case 2:
        int x;
        cout<<"\n Enter the location where you want to run min heapify";
        cin>>x;
    h1.min_heapify(a,x);
    h1.show(a);
    break;
    case 3:
        int k;
        cout<<"\n Enter the value you want to insert";
        cin>>k;
    h1.min_heap_insert(a,k);
    h1.show(a);
    break;
    case 4:
        int p,w;
        cout<<"\n Enter the location and key value you want to replace";
        cin>>w;
        cin>>p;
    h1.heap_dec_key(a,w,p);
    h1.show(a);
    break;
    case 5:
    h1.extract_min(a);
    h1.show(a);
    break;
        case 6:
    h1.heap_min(a);
    h1.show(a);
    break;
    }
    }while(ch!=0);

    return 0;
}
