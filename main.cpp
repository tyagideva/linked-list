#include <iostream>
#include<stack>

using namespace std;


int prec(char c)
{
    if(c =='^')
        return 3;
        else if(c == '*'|| c=='/')
            return 2;
        else if(c =='+'||c == '-')
            return 1;
        else
            return -1;

}

bool isoperator(char c)
{
if(c =='+'||c =='-'||c =='*'||c =='/'||c=='^')
{
    return true;

}
else
    return false;
}

string infixtopostfix(stack <char> s , string infix)
{
     string post ;
     for (int i =0 ;i<infix.length();i++)
     {
         if(infix[i]>='a'&&infix[i]<='z')
         {
             post+= infix[i];
         }
         else if(infix[i]=='(')
         {

                 s.push(infix[i]);
         }
         else if(infix[i]==')')
         {
             while(s.top()!= '('&& (!s.empty()))
             {
                 char temp = s.top();
                post+= temp;
                 s.pop();
            }
            }
else if(isoperator(infix[i]))
    {
    if(s.empty())
    {
        s.push(infix[i]);
        }
            else
        {
        if(prec(infix[i])>prec(s.top()))
        {
        s.push(infix[i]);

            }
        else if((prec(infix[i])==prec(s.top()))&&(infix[i]=='^'))
            {s.push(infix[i]);
            }
            else
                {
            while(!s.empty()&&prec(infix[i])<=prec(s.top()))
               {
                char temp = s.top();
                post += temp;
                    s.pop();

                }
                s.push(infix[i]);

                }

         }

     }
     }
     while(!s.empty())
     {
         post+= s.top();
         s.pop();

     }



     return post;
}

int main()
{

    string infix, postfix;
    cout<<"\n enter the infix expression";
    cin>>infix;
    stack <char> s;
    cout<<"infix exp."<<infix;
    postfix = infixtopostfix(s,infix);
    cout<<endl<<"postfix exp"<<postfix;
    return 0;
}
