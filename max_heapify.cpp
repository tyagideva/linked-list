#include <iostream>

using namespace std;
void max_heapify(int a[],int n,int size)
{int largest;
    int l = 2*n;
    int r = 2*n+1;
    if(l<=size&&a[l]>a[n])
    {largest = l;

    }
    else
        largest = n;
    if(r<=size&&a[r]>a[largest])
        largest = r;
    if (largest!=n)
    {
        int temp = a[n];
        a[n] = a[largest];
        a[largest] = temp;
        max_heapify(a,largest,size);
    }


}

int main()
{int n;
int a[15];
    cout <<"Enter the size of heap";
    cin>>n;
    for(int i = 1;i<=n;i++)
        cin>>a[i];
        max_heapify(a,2,n);
        cout<<"array";
        for (int i = 1;i<=n;i++)
        {
            cout<<" "<<a[i];
        }


    return 0;
}
