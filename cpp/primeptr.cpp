#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
    unsigned long int i, max;
    time_t rawtime;
    struct tm * timeinfo;
   // cout<<"\033[2J\033[1;1H"
    system("clear");
    cout<<"\nEnter number to check prime factors :";
    cin>>max;

    
    time(&rawtime);
    timeinfo= localtime(&rawtime);
    bool *num= new bool;

    *num=false;
    *++num=false;
    for(i=2; i<=max; i++)
        *++num=true;
    num=num-max+1;  //pointer to num for value holder 1

    //for(i=0; i<=max; i++)
      //  cout<<i<<" ; "<<*num++<<endl;
    
    //num=num-i+1;      //pointer to num for value holder 1
    for(i=2; i<=max; i++)
    {
        num++;
        if(*num==true)
        {
            int j=1;
            for(; i*(j+1)<=max; j++)
            {
                num=num+i;
                *num=false;
            }
            num=(num-j*i)+i;
        }
    }
    
    num=num-max;
    cout<<"\n";
    for(i=0; i<=max; i++)
    {
        if(*num)
            cout<<i<<" ";
        num++;
        //cout<<i<<" ; "<<*num++<<endl;
    }
    
 //   system("pause");
    cout<<"\nPrime1 start time :"<<asctime(timeinfo)<<endl;    
    time(&rawtime);
    timeinfo= localtime(&rawtime);
    cout<<"Prime1 end time :"<<asctime(timeinfo);

    //num=num-max-1;
    //delete num;
    return 0;
}