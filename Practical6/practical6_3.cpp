#include<iostream>
#include<string>
using namespace std;

int precedence(char op)
{
    if(op=='^')
        return 3;
    if(op=='*'||op=='/')
        return 2;
    if(op=='+'||op=='-')
        return 1;
    return 0;
}

int main()
{
    string infix;
    cout<<"Enter infix expression: ";
    cin>>infix;

    char stac[100];
    int top=-1;
    string postfix="";

    for(int i=0;i<infix.length();i++)
    {
        char ch=infix[i];

        if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||(ch>='0'&&ch<='9'))
        {
            postfix+=ch;
        }
        else if(ch=='(')
        {
            stac[++top]=ch;
        }
        else if(ch==')')
        {
            while(top!=-1&&stac[top]!='(')
            {
                postfix+=stac[top--];
            }

            if(top!=-1)
                top--;
        }
        else
        {
            while(top!=-1&&precedence(stac[top])>=precedence(ch))
            {
                postfix+=stac[top--];
            }

            stac[++top]=ch;
        }
    }

    while(top!=-1)
    {
        postfix+=stac[top--];
    }

    cout<<"Postfix expression: "<<postfix<<endl;

    return 0;
}
