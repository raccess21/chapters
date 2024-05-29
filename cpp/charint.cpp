#include "C:/rahul/CodeBlock/custom.cpp"
using namespace std;

int main()
{
    char t1[]="-365", t2[]="-1024";
    char t[50];
    long int n1=0, n2=0, sign=1;
    int len1=strlen(t1);
    int len2=strlen(t2);
    long add=0, addtmp;
    int i, j;


    cout<<"\nT1="<<t1;
    cout<<"\nT2="<<t2;

    cout<<"\nN1="<<n1;
    cout<<"\nN2="<<n2;
    cout<<"\nN1 + N2="<<char2int(t1)+char2int(t2);

    int digit=1;
    for(i=0; digit!=0; i++)
        digit=add/(pow(10,i));
    digit=--i;
    cout<<"\nDigits in N2:"<<digit;

    j=0;
    for(i=digit-1; i>=0; i--)
    {
        long int re=pow(10,i);
        t[j++]='0'+(char)(addtmp/re);
        addtmp=addtmp%re;
    }

    t[j]='\0';

    cout<<"\nT="<<t;
    //for(i=0; t[i]!='\0'; i++)
    //cout<<"\t"<<t;
/*
    string str;
    cout<<"\nEnter name:";

    len1=strlen(str);
    cout<<"\nLen="<<len1;
    //cout<<"\nName="<<str;
  */  return 0;
}
