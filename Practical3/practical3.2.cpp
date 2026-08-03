#include<iostream>
#include<string>
using namespace std;
int main(){
    int ar[10]={11,12,34,43,23,22,55,66,44,100};
    int temp=0;


        for(int i=0;i<10;i++)
        {
            for(int j=i+1;j<10;j++){

                if(ar[j]<ar[i]){
                temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
                }
            }
        }


        for(int i=0;i<10;i++)
        {
            cout<<ar[i]<<" ";
        }

        return 0;
}
