#include<iostream>
#include<fstream>
using namespace std;

long int totalsize(char, char, ifstream&);

int main()
{
    long int i=0;
    char ch;
    ifstream fin;
    fin.open("C:/rahul/CodeBlock/testalgo.txt", ios::in);
    cout<<"\nReading file:";
    cin>>ch;
    i=totalsize(',', '@', fin);
    cout<<"\nFile size="<<i;
    fin.close();
    return 0;
}

long int totalsize(char test_val, char end_val, ifstream& f)
{   char ch1;
    cout<<"\ncalculating file:";
    cin>>ch1;
    long int i=0;
    char ch;
    while(ch!=end_val)
    {
        f.get(ch);
        if(ch==test_val)
            i++;
    }

    return i;
}
