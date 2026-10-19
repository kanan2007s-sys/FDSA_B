
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> table[10];
    int n,code;

    cout<<"Enter number of books: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter book code: ";
        cin>>code;

        int h=code%10;
        table[h].push_back(code);
    }

    cout<<"Shelf contents:"<<endl;

    for(int i=0;i<10;i++)
    {
        cout<<i<<" : ";

        if(table[i].empty())
            cout<<"Empty";

        for(int j=0;j<table[i].size();j++)
            cout<<table[i][j]<<" ";

        cout<<endl;
    }

    return 0;
}
