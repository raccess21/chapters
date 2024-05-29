#include<iostream>
using namespace std;

unsigned int len=16, i=1;
unsigned long int byte=1, past=1;

void byterec()
{
    past*=2;
    byte+=past;
    i++;
    if(i<len)
        byterec();
}

void byteloop()
{
    for(i=1;i<len;i++)
    {
        past*=2;
        byte+=past;
    }
}

int main()
{

    //cout<<"\nEnter size in bits:";
    //cin>>len;
    byterec();
    //byteloop();
    cout<<"\nlen="<<len;
    cout<<"\nMax="<<byte;
    return 0;
}
