#include<iostream>
#include<fstream>
using namespace std;

class decimal
{
    public:
    long numi;
    double numf;

    int num(double val)
    {
        numi=(int)val;
        numf=val-numi;
    }
};

int main()
{
    decimal data;
    double dec[3]={100.1234, 9999.1234567890123456789, 1000.1234567};
    //double deci=-225.339;
    long num[3], bum=1;
    long double numf[3];
    long i=0;

    /*for(;i<3;i++)
    {
        num[i]=(int)dec[i];
        numf[i]=(double)(dec[i]-num[i]);
        data[i].num=num[i];
        data[i].numf=numf[i];
        fout.write((char*)&data, sizeof data);
    }*/

    bum*=data.numf*100000000;

    cout<<bum;
   /* for(i=0;i<3;i++)
    {
        cout<<"\n"<<dec[i]<<":"<<num[i]<<":"<<numf[i];

    }*/
   // cout<<"\ndesi="<<deci;
   // fout<<"\ndesi="<<deci;
    return 0;
}
