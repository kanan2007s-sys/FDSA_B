#include<iostream>
#include<string>
using namespace std;

class Node
{
public:
    string name;
    Node* next;
    Node* prev;

    Node(string name)
    {
        this->name=name;
        next=nullptr;
        prev=nullptr;
    }
};

Node* shead=nullptr; //head for singly circular LL
Node* dhead=nullptr; //head for double circular LL

void SinglyAdd(string name,int pos)
{
    Node* data=new Node(name);

    if(shead==nullptr)
    {
        shead=data;
        data->next=shead;
        return;
    }

    if(pos==1)
    {
        Node* p=shead;
        while(p->next!=shead)
        {
            p=p->next;
        }
        data->next=shead;
        p->next=data;
        shead=data;
        return;
    }

    Node* p=shead;
    for(int i=1;i<pos-1 && p->next!=shead;i++)
    {
        p=p->next;
    }

    data->next=p->next;
    p->next=data;
}

void SinglyRemove(int pos)
{
    if(shead==nullptr)
    {
        cout<<"Circle is empty"<<endl;
        return;
    }

    if(shead->next==shead)
    {
        delete shead;
        shead=nullptr;
        return;
    }

    if(pos==1)
    {
        Node* p=shead;
        while(p->next!=shead)
        {
            p=p->next;
        }
        Node* temp=shead;
        shead=shead->next;
        p->next=shead;
        delete temp;
        return;
    }

    Node* p=shead;
    for(int i=1;i<pos-1 && p->next!=shead;i++)
    {
        p=p->next;
    }

    Node* temp=p->next;
    p->next=temp->next;
    delete temp;
}

void SinglyDisplay()
{
    if(shead==nullptr)
    {
        cout<<"Circle is empty"<<endl;
        return;
    }

    Node* p=shead;
    do
    {
        cout<<p->name<<" ";
        p=p->next;
    }
    while(p!=shead);

    cout<<endl;
}

void DoublyAdd(string name,int pos)
{
    Node* data=new Node(name);

    if(dhead==nullptr)
    {
        dhead=data;
        data->next=dhead;
        data->prev=dhead;
        return;
    }

    if(pos==1)
    {
        Node* last=dhead->prev;

        data->next=dhead;
        data->prev=last;
        last->next=data;
        dhead->prev=data;
        dhead=data;
        return;
    }

    Node* p=dhead;
    for(int i=1;i<pos-1 && p->next!=dhead;i++)
    {
        p=p->next;
    }

    data->next=p->next;
    data->prev=p;
    p->next->prev=data;
    p->next=data;
}

void DoublyRemove(int pos)
{
    if(dhead==nullptr)
    {
        cout<<"Circle is empty"<<endl;
        return;
    }

    if(dhead->next==dhead)
    {
        delete dhead;
        dhead=nullptr;
        return;
    }

    if(pos==1)
    {
        Node* temp=dhead;
        Node* last=dhead->prev;

        dhead=dhead->next;
        dhead->prev=last;
        last->next=dhead;

        delete temp;
        return;
    }

    Node* p=dhead;
    for(int i=1;i<pos && p->next!=dhead;i++)
    {
        p=p->next;
    }

    p->prev->next=p->next;
    p->next->prev=p->prev;

    delete p;
}

void DoublyDisplay()
{
    if(dhead==nullptr)
    {
        cout<<"Circle is empty"<<endl;
        return;
    }

    Node* p=dhead;

    do
    {
        cout<<p->name<<" ";
        p=p->next;
    }
    while(p!=dhead);

    cout<<endl;
}

int main()
{
    int choice,pos;
    string name;

    while(true)
    {
        cout<<"1.Singly Circular Add"<<endl;
        cout<<"2.Singly Circular Remove"<<endl;
        cout<<"3.Singly Circular Display"<<endl;
        cout<<"4.Doubly Circular Add"<<endl;
        cout<<"5.Doubly Circular Remove"<<endl;
        cout<<"6.Doubly Circular Display"<<endl;
        cout<<"7.Exit"<<endl;

        cin>>choice;

        if(choice==1)
        {
            cout<<"Enter student name: ";
            cin>>name;
            cout<<"Enter position: ";
            cin>>pos;
            SinglyAdd(name,pos);
            SinglyDisplay();
        }
        else if(choice==2)
        {
            cout<<"Enter position: ";
            cin>>pos;
            SinglyRemove(pos);
            SinglyDisplay();
        }
        else if(choice==3)
        {
            SinglyDisplay();
        }
        else if(choice==4)
        {
            cout<<"Enter student name: ";
            cin>>name;
            cout<<"Enter position: ";
            cin>>pos;
            DoublyAdd(name,pos);
            DoublyDisplay();
        }
        else if(choice==5)
        {
            cout<<"Enter position: ";
            cin>>pos;
            DoublyRemove(pos);
            DoublyDisplay();
        }
        else if(choice==6)
        {
            DoublyDisplay();
        }
        else if(choice==7)
        {
            break;
        }
    }

    return 0;
}
