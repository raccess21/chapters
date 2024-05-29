#include<iostream>
#include "C:/rahul/CodeBlock/custom.cpp"
using namespace std;

int main()
{
    int i=0, j=0, val=0;
    int *in;

    while(check()==1)
    {
        cout<<"\nEnter value "<<i+++1<<":";
        cin>>*in++;
    }

    j=i;
    in-=j;
    i=0;

    while(i<j)
    {
        cout<<"\nValue "<<i+++1<<"="<<*in++;
    }

    cout<<"\nDeleting pointer.";
    in-=j;
    delete in;
    return 0;
}
