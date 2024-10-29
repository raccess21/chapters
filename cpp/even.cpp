#include<iostream>
using namespace std;

int main()
{
    unsigned long int num, diff, i, sum, square;
    sum=square=0;

    cout<<"\nEnter a number :";
    cin>>num;
    cout<<"\nEnter difference :";
    cin>>diff;

    for(i=1; i<=num;)
    {
        square=i*i;
        sum+=square;
        cout<<"\nSquare of "<<i<<" is :"<<square;
        i=i+diff;
    }
    cout<<"\nSum of series is :"<<sum;
}