#include <iostream>
#include <time.h>
using namespace std;

int prime2(unsigned long int &max)
{
    unsigned long int i=2, j;
    unsigned long check, op;
    check=op=0;
   // cout<<"\nPrimes2 : ";
    for(; i<=max; i++)
    {
        int factor =1;
        for(unsigned long j=1; j<=i/2; j++)
        {
            //check++;
            if(i%j == 0)
            {
                factor++;  
               // op++;
            }
        }

        //check++;
        if(factor==2)
        {
            //cout<<i<<" ";
          //  op++;
        }
    }

    //cout<<"\nTotal checks = "<<check;
    //cout<<"\nTotal ops = "<<op;
    
    return 0;
}

int check_prime(int num)
{
    unsigned long check, op;
    check=op=0;
    int factor=1;
    cout<<"\nFactors of "<<num<<" : ";
    for(int j=1; j<=num/2; j++)
    {
        check++;
        if(num%j==0)
        { 
            op++;  
            cout<<j<<" ";
            factor++;
        }
    }

    cout<<num;
    cout<<"\nTotal factors = "<<factor;
    cout<<"\nTotal checks = "<<check;
    cout<<"\nTotal ops = "<<op;
    return 0;
}

int prime1(unsigned long int &max)
{
    unsigned long int i=2;
    int last=0;
    unsigned long check, op;
    check=op=0;
    bool num[max+1], diff[max+1], pc=0;
    
    for(i=0; i<=max; i++)
        num[i]=true;

    for(i=2; i<=max; i++)
    {
        //check++;
        if(num[i]==1)
        {
            for(int j=2; i*j<=max; j++)
            {
                //op++;
                num[i*j]=false;
            }

            //diff[pc++]=i-last;
            //last=i;
        }
    }

    //cout<<"\nPrimes1 ("<<pc<<") : ";
    cout<<"\n";
    for(i=2; i<=max; i++)
    {
        //check++;
        if(num[i]==true)
        {
          //  op++;
            cout<<i<<" ";
        }
    }

  /*  cout<<"\ndiff : ";
    for(i=0; i<pc; i++)
        cout<<diff[i]<<" "; 
    
    cout<<"\nTotal checks = "<<check;
    cout<<"\nTotal ops = "<<op; */
    return 0;
}

int main()
{
    unsigned long int max=10; 
    time_t rawtime;
    struct tm * timeinfo;
    //cout<<"\nEnter max range for prime : ";
    cout<<"\nEnter number to check prime factors :";
    cin>>max;

    time(&rawtime);
    timeinfo= localtime(&rawtime);
    cout<<"\nPrime1 start time :"<<asctime(timeinfo);
    prime1(max);        //check=1992,   operation=2120 for max=997
    
    time(&rawtime);
    timeinfo= localtime(&rawtime);
    cout<<"\nPrime2 start time :"<<asctime(timeinfo);
    prime2(max);        //check=249498, operation=6212 for max=997
    
    //cc
    time(&rawtime);
    timeinfo= localtime(&rawtime);
    cout<<"\nPrime2 end time :"<<asctime(timeinfo);
    cout<<"\n";
    
    return 0;
}