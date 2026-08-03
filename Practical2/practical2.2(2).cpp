#include<iostream>
using namespace std;

int search(int a[],int low,int high,int key)
{
if(low>high)
return -1;

int mid=(low+high)/2;

if(a[mid]==key)
return mid;

if(key<a[mid])
return search(a,low,mid-1,key);
else
return search(a,mid+1,high,key);
}

int main()
{
int a[]={2001,2003,2005,2008,2011,2022,2026};
int key;

cout<<"Enter book code: ";
cin>>key;

int ans=search(a,0,6,key);//(array,low,high,value/key)

if(ans==-1)
cout<<"Book not found";
else
cout<<"Book found at position "<<ans+1;

return 0;
}
