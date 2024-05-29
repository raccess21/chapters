#include<iostream>
using namespace std;

void display(int product[20], int i=0)
{
    int j=0;
    if(i==0)
    cout<<"\nValue of product is:";
    else
        cout<<"\nValue of product after "<<i<<" iteration:";

    while(product[j]==0)
        j++;
    for(; j<20 ;j++)
    cout<<product[j];
}

int main()
{
    int product[20], i=1, print ,j=4, add=0, quo=0, rem=0;
    char ch='y';
    for(i=0;i<19;i++)
    product[i]=0;
    product[19]=1;

    display(product);

    for(i=1; i<20; i++)
    {
        while(j>=0)
        {
            add=(product[j]*i)+quo;
            quo=add/10;
            rem=add%10;
            product[j]=rem;
            j--;
        }
        j=19;
        display(product,i);
    }

    display(product);

    return 0;
}
