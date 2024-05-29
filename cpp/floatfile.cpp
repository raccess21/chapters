#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream fin;
    char ch;
    int data=0;
    int i=0;
    fin.open("C:/rahul/CodeBlock/testalgo.txt", ios::in);

    while(!fin.eof())
    {
        fin>>data;
        fin>>ch;
        cout<<"\n "<<i++<<":"<<data;
    }

    fin.close();
    return 0;
}
