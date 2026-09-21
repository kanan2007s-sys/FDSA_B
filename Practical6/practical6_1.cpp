#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter maximum capacity of stack: ";
    cin>>n;

    int stac[n];
    int top=-1;
    int choice;

    do
    {
        cout<<"\n1. Place tray";
        cout<<"\n2. Take tray";
        cout<<"\n3. View top tray";
        cout<<"\n0. Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                if(top==n-1)
                {
                    cout<<"Error: Stack is full. Cannot place tray."<<endl;
                }
                else
                {
                    top++;
                    stac[top]=top+1;
                    cout<<"Tray placed successfully."<<endl;
                    cout<<"Current top tray: "<<stac[top]<<endl;
                }
                break;
            }

            case 2:
            {
                if(top==-1)
                {
                    cout<<"Error: Stack is empty. Cannot take tray."<<endl;
                }
                else
                {
                    cout<<"Tray taken: "<<stac[top]<<endl;
                    top--;

                    if(top==-1)
                        cout<<"Stack is now empty."<<endl;
                    else
                        cout<<"Current top tray: "<<stac[top]<<endl;
                }
                break;
            }

            case 3:
            {
                if(top==-1)
                {
                    cout<<"Stack is empty. No tray available."<<endl;
                }
                else
                {
                    cout<<"Current top tray: "<<stac[top]<<endl;
                }
                break;
            }

            case 0:
                cout<<"Exiting program..."<<endl;
                break;

            default:
                cout<<"Invalid choice."<<endl;
        }

    }while(choice!=0);

    return 0;
}
