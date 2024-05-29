#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream fin;
    int c=0;
    char ch;
    fin.open("C:/Users/Arun Kumar Das/Desktop/doosra.txt", ios::in);

    while(ch!='@')
    {
        fin.get(ch);
        if(ch=='/n')
            c++;
    }
    cout<<"\nLines="<<c;
    return 0;
}
