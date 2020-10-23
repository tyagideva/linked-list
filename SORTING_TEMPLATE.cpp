#include <iostream>

using namespace std;
template<class T>
class sort{
public:
T a[10];
int n;


    void sel_sort(T a[])
    {
       T temp;
       for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			    min=j;
		}
		T temp=a[min];
		a[min]=a[i];
		a[i]=temp;


               }



       for (int i = 0;i<n;i++)
        cout<<" "<<a[i];

    }
    void bubblesort(T a[])
    {
        T temp;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
        cout<<"jk";
        for (int i = 0;i<n;i++)
        cout<<" " <<a[i];

    }
    void insertionsort(T a[])
    {
        for(int i = 1;i<n;i++)
        {
            T k = a[i];
            int j = i-1;
            while(j>=0&&k<a[j])
            {
                a[j+1] = a[j];
                j = j-1;
            }
            a[j+1] = k;

            }
        for (int i = 0;i<n;i++)
        cout<<" " <<a[i];
    }

              };

int main()
{ sort <int>ob;

    cout << "Enter the number of elements" << endl;
    cin>>ob.n;
    for(int i = 0;i<ob.n;i++)
    {
        cin>>ob.a[i];
    }
    int ch;
    cout<<"\n Enter your choice\n1:bubble sort\n2:insertion sort\n3:selection sort\n";
    cin>>ch;
    switch(ch)
    {
    case 1:
        cout<<"\n using bubble sort";
        ob.bubblesort(ob.a);
        break;
    case 2:
    cout<<"\nusing insertion sort";
    ob. insertionsort(ob.a);
        break;
    case 3:
        cout<<"\nusing selection sort";
    ob.sel_sort(ob.a);
    break;
    }



    return 0;
}
