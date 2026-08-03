#include<iostream>
#include<string>
using namespace std;
int main()
{
int plate[100]={0}; // the capacity of parking is 100

int n=0;//number plate to find
int j=0;//temporary stores how many cars


cout<<"Enter the car number plates and press 0 for exit : ";
for(int i=0;i<100;i++)
{
    cin>>plate[i];
    if(plate[i]==0)
    {
        j=i;
        break;
    }
}

cout<<"Enter the plate number of the car to find: ";
cin>>n;

    for(int i=0;i<j;i++)
    {
        if(plate[i]==n)
        {
            cout<<"The car with plate number "<<n<<"was at "<<i+1<<"th position"<<endl;
        }
    }
    return 0;
}

