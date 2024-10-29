#include <iostream>
using namespace std;

int main()
{
    int n=1, up, down;
    char sign='+';

    cout<<"\nEnter length of series to print :";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        if(i%2==0)
            sign='-';
            else
                sign='+';
        cout<<sign<<i<<"/(3^"<<i<<")  ";
    }

    return 0;
}