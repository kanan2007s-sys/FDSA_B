#include<iostream>
#include<string>
using namespace std;
class Song
{
    string song=" ";
    Song* next;
    Song* prev;
public:
    Song(string song)
    {
        next=nullptr;
        prev=nullptr;
        this->song=song;
    }
    friend void Addatfront(string sng);
    friend void Addatend(string sng);
    friend void Addinbet(string sng);
    friend void remove();
    friend void display();
    friend int count();
};
Song* head=nullptr;
void Addatfront(string sng)
{
    Song* data=new Song(sng);
    if(head==nullptr)
    {
        head=data;
    }
    else
    {
        data->next=head;
        head->prev=data;
        head=data;
    }
}
void Addatend(string sng)
{
    Song* data=new Song(sng);
    if(head==nullptr)
    {
        head=data;
    }
    else
    {
        Song* p=head;
        while(p->next!=nullptr)
        {
            p=p->next;
        }
        p->next=data;
        data->prev=p;
    }
}
void Addinbet(string sng)
{
    Song* data=new Song(sng);
    string current;
    cout<<"Enter the song after which to insert: ";
    cin>>current;
    Song* p=head;
    while(p!=nullptr && p->song!=current)
    {
        p=p->next;
    }
    if(p==nullptr)
    {
        cout<<"Song not found"<<endl;
        delete data;
        return;
    }
    data->next=p->next;
    data->prev=p;
    if(p->next!=nullptr)
    {
        p->next->prev=data;
    }
    p->next=data;
}
void remove()
{
    if(head==nullptr)
    {
        cout<<"No song to remove , playlist is empty"<<endl;
    }
    else
    {
        Song* p=head;
        head=head->next;
        if(head!=nullptr)
        {
            head->prev=nullptr;
        }
        delete p;
        cout<<"Successfully removed..."<<endl;
    }
}
int count()
{
    int c=0;
    Song* p=head;
    while(p!=nullptr)
    {
        c++;
        p=p->next;
    }
    return c;
}
void display()
{
    Song* p=head;
    if(head==nullptr)
    {
        cout<<"Playlist is empty"<<endl;
        return;
    }
    while(p!=nullptr)
    {
        cout<<p->song<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    int n=0;
    string song=" ";
    while(true)
    {
        cout<<"Enter \n1.To add song at beginning of playlist: \n2.To add song at end \n3.To add song after a specific song \n4.To remove first song \n5.To count songs \n6.To display playlist \n7.To exit"<<endl;
        cin>>n;
        if(n==1)
        {
            cout<<"Enter the song name: ";
            cin>>song;
            Addatfront(song);
        }
        else if(n==2)
        {
            cout<<"Enter the song name: ";
            cin>>song;
            Addatend(song);
        }
        else if(n==3)
        {
            cout<<"Enter the song name: ";
            cin>>song;
            Addinbet(song);
        }
        else if(n==4)
        {
            remove();
        }
        else if(n==5)
        {
            cout<<"Number of songs: "<<count()<<endl;
        }
        else if(n==6)
        {
            display();
        }
        else if(n==7)
        {
            break;
        }
        else
        {
            cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}
