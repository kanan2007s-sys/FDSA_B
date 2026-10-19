
#include<iostream>
using namespace std;

int main()
{
    int table[10],n,id;

    for(int i=0;i<10;i++)
        table[i]=-1;

    cout<<"Enter number of students: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter student ID: ";
        cin>>id;

        int h1=id%10;
        int h2=(id%2==0)?3:7;
        int j=0;

        while(j<10 && table[(h1+j*h2)%10]!=-1)
            j++;

        if(j==10)
            cout<<"Hash table full"<<endl;
        else
            table[(h1+j*h2)%10]=id;
    }

    cout<<"Hash table:"<<endl;

    for(int i=0;i<10;i++)
    {
        cout<<i<<" : ";

        if(table[i]==-1)
            cout<<"Empty";
        else
            cout<<table[i];

        cout<<endl;
    }

    return 0;
}
