#include<iostream>
using namespace std;

int test(int i)
{

    switch (i)
    {
        case 1: cout<<"\none";  break;
        case 2: cout<<"\ntwo";  break;
        case 3: cout<<"\nthree";  break;
        case 4: cout<<"\nfour";  break;
        case 5: cout<<"\nfive";  break;
        case 6: cout<<"\nsix";  break;
        case 7: cout<<"\nseven";  break;
        case 8: cout<<"\neight";  break;
        case 9: cout<<"\nnine";  break;
        case 10: cout<<"\nten";  break;
        case 0: cout<<"\nzero";  break;
        default: cout<<"\nerror";   return 0;
    }
    return 1;
}

int main()
{
    int i=11;
    cout<<"\n"<<test(i);
    return 0;
}

