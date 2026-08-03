#include<iostream>
#include<string>
using namespace std;
int main(){
   int ar1[10]={10,23,34,45,65,43,455,56,35,100};
   int ar2[10]={0};
   int tempL=0,tempH=0;
   ar2[0]=ar1[0];


   for(int i=0;i<10;i++){
        if(ar2[0]<ar1[i])
        {
            tempH=ar1[i];
        }
        else if(ar2[0]>ar1[i])
        {
            tempL=ar1[i];
        }

   }

return 0;
}
