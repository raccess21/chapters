#include<iostream>
using namespace std;

int main()
{
    int i=0;

    cout<<i;
    cout<<i++;
    if(i--==0)
        cout<<"\ni=0";
        else
        cout<<"\ni=1";
    cout<<"\ni="<<i;
    return 0;
}
