#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;

int main()
{
    ifstream fin;
    char ch='y';
    int len=0;
    fin.open("C:/rahul/ecom/myntra/2109rawrev.txt", ios::in);
    if(!fin)
    {
        cout<<"\nError opening file.";
        exit(0);
    }


    while(ch!='\n')
    {
        fin.get(ch);
        if(ch==',')
        len++;
    }
    //cout<<"\nBlock size is "<<len-1<<" bytes.";
    cout<<"\ncomma="<<len;
    /*while(ch!='\n')
    {
        fin.get(ch);
        len++;
    }
    cout<<"\nBlock size is "<<len-1<<" bytes.";
    */fin.close();
    return 0;
}
