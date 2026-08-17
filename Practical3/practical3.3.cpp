#include <iostream>
using namespace std;

int main()
{
    int marks[5] ={70,50,90,60,80};
    int key;
    for(int i=1;i<5;i++)
    {
        key=marks[i];
        int j = i-1;

        while(j>=0 && marks[j]>key)
        {
            marks[j+1]=marks[j];
            j--;
        }

        marks[j+1]=key;
    }

    cout<<"Sorted marks: ";

    for(int i = 0; i < 5; i++)
    {
        cout << marks[i] << " ";
    }

    return 0;
}
