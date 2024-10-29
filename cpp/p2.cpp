#include <iostream>
using namespace std;

int main()
{
    int i, max;

    cout<<"\nEnter max range for perfect square check : ";
    cin>>max;

    cout<<"\nAll perfect squares are:\n";
    for(i=0; i*i<=max; i++)
        cout<<i<<" : "<<i*i<<"\n";

    return 0;
}