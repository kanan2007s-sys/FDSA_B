#include<iostream>
#include<string>
using namespace std;


int main(){
int ar[10]={0,1,1,1,2,2,1,0,0,2};
int temp=0;

for(int i=0;i<10;i++)
{
    for(int j=i;j<10;j++)
    {
       if(ar[i]>ar[j])
       {
            temp=ar[i];
            ar[i]=ar[j];
            ar[j]=temp;
       }
    }
}


cout<<"So the final array with Selection sort is: ";

for(int i=0;i<10;i++)
{
    cout<<ar[i]<<" ";
}

return 0;
}
