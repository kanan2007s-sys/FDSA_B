#include<iostream>
#include<string>
using namespace std;
int main(){
int marks[10]={50,67,76,54,100,37,73,91,19,82};
int temp=0;


cout<<"The unsorted marks of students are : ";
for(int i=0;i<10;i++)
{
    cout<<marks[i]<<" ";
}

//sorting
for(int i=0;i<10;i++)
{
    for(int j=0;j<10;j++)
    {
        if(marks[j]>marks[j+1])
        {
            temp=marks[j];
            marks[j]=marks[j+1];
            marks[j+1]=temp;

        }
    }
}

cout<<endl<<endl;

cout<<"sorted marks of students :";
    for(int i=0;i<10;i++)
    {
        cout<<marks[i]<<" ";

    }

    cout<<endl;

return 0;
}
