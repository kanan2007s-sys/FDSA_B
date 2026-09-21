#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data=value;
        next=NULL;
    }
};

int main()
{
    Node* top=new Node(1);
    int CASE;

    do
    {
        cout<<"\nEnter 1 to visit next page, 2 to go back, 0 to exit: ";
        cin>>CASE;

        if(CASE==1)
        {
            int page=top->data+1;

            Node* newNode=new Node(page);
            newNode->next=top;
            top=newNode;

            cout<<"Current page: "<<top->data<<endl;
        }

        else if(CASE==2)
        {
            if(top->next==NULL)
            {
                cout<<"No history left. Cannot go back."<<endl;
            }
            else
            {
                Node* temp=top;
                top=top->next;
                delete temp;

                cout<<"Current page: "<<top->data<<endl;
            }
        }

        else if(CASE==0)
        {
            cout<<"Exiting..."<<endl;
        }

        else
        {
            cout<<"Invalid choice."<<endl;
        }

    }while(CASE!=0);

    return 0;
}
