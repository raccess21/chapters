#include<iostream>
using namespace std;

int main()
{
    double data[10000], dataf[10000], total=0, totalf=0;
    long int datai[10000], i, totali=0;

    for(i=0;i<10000;i++)
    {
        data[i]=100.000001;
        datai[i]=(int)data[i];
        dataf[i]=(double)(data[i]-datai[i]);
    }

    for(i=0;i<10000;i++)
    {
        totali+=datai[i];
        totalf+=dataf[i];
    }
    total=(double)(totali+totalf);
    cout<<"\nTotal="<<total;
    return 0;
}
