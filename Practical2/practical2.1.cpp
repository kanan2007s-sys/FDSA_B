#include<iostream>
#include<string>
using namespace std;
int main()
{
    int ar[10]={1001,1002,1003,1004,1005,1006,1007,1008,1009,1010};
    int mid=0,start=0,last=9;
    int plate=0,key=0;

    cout<<"Enter the plate number : ";
    cin>>plate;
    for(int i=0;i<=last;i++)
    {
        mid=(start+last)/2;
        if(ar[mid]>plate)
        {
            last=mid-1;
        }
        else if(ar[mid]<plate)
        {
            start=mid+1;
        }
        else
        {
            key=mid;
           // cout<<"The number is at : "<<mid+1<<"position";
        }



    }
    cout<<"The value/position of Car is : "<<key;
}
