#include <iostream>
#include<stack>
using namespace std;

void eval(stack <int> n,string s)
{int n1,n2,n3;
    for(int i =0;i<s.length();i++)
    {
        if((s[i]>='1')&&(s[i]<='9'))
        n.push(s[i]-'0');
        else
          {

            n1 = n.top();
            n.pop();
        n2 = n.top();
        n.pop();
        if(s[i]=='*')
            n.push(n2*n1);
        else if(s[i]=='+')
            n.push(n1+n2);
            else if(s[i]=='-')
            n.push(n2-n1);
            else if(s[i]=='/')
            n.push(n1/n2);


    }}
    n3 = n.top();
    cout<<n3;
}
int main()
{
 stack <int> n;
string s;
cout<<"enter the postfix expression";
cin>>s;
eval(n,s);
return 0;
}
