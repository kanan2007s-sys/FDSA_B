#include<iostream>
using namespace std;

int main()
{
    int table[10],n,id;
    for(int i=0;i<10;i++)
        table[i]=-1;

    cout<<"Enter number of vehicles: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter registration number: ";
        cin>>id;

        int h=id%10;
        int j=0;

        while(j<10 && table[(h+j)%10]!=-1)
            j++;

        if(j==10)
            cout<<"Parking lot full"<<endl;
        else
            table[(h+j)%10]=id;
    }

    cout<<"Parking slots:"<<endl;

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
