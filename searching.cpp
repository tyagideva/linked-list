#include <iostream>

using namespace std;
template<class T>
class searching{
public:
T a[10];
int n;


  void sort(T a[])

{
    for(int i = 0;i<n;i++)

    {
        int min = i;
        for(int j = i+1;j<n;j++)
        {
            if(a[j]<a[min])
                min = j;
        }
        T temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    for(int i = 0;i<n;i++)
    {
        cout<<" "<<a[i];
    }

    }

void search(T a[],T el)
{int flag = 0;
    for(int i = 0;i<n;i++)
    {
        if(a[i]==el)
        {
            cout<<"Found at :"<<i+1;
            flag = 1;
            break;
        }

    }
    if(flag == 0)
        cout<<-1;
}
              };

int main()
{ searching <int>ob;
int el;

    cout << "Enter the number of elements" << endl;
    cin>>ob.n;
    for(int i = 0;i<ob.n;i++)
    {
        cin>>ob.a[i];
    }
    ob.sort(ob.a);
    cout<<"\nEnter the element you want to find";
    cin>>el;
    ob.search(ob.a,el);

    return 0;
}
