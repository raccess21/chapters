#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    float a;
    char ch;
    fin.open("C:/rahul/ecom/myntra/testalgo.txt", ios::in);
    fout.open("C:/rahul/ecom/myntra/testalgoo.txt", ios::out);
    while(1)
    {
        fin>>a;
        if(fin.eof())
            break;
        else if(!a)
            a=0.0;
        fin.get(ch);
        cout<<"\n"<<a;
        fout<<a<<ch;

    }
    return 0;
}
