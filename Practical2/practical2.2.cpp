#include<iostream>
using namespace std;

int main()
{
int plate[]={2001,2003,2005,2008,2011,2022,2026};
int size=7;
int n;

cout<<"Enter the book code: ";
cin>>n;

int low=0,high=size-1;

while(low<=high)
{
int mid=(low+high)/2;

if(plate[mid]==n)
{
cout<<"Book code found at position "<<mid+1;
return 0;
}

if(n<plate[mid])
high=mid-1;
else
low=mid+1;
}

cout<<"Book code not found.";

return 0;
}
