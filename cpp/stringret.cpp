#include<iostream>
#include<fstream>
using namespace std;

char* st(char path[101])
{
    return path;
}

int main()
{
    char name[101], ch;
    char *nam= new char;
    ifstream fin;
    cout<<"\nEnter filepath to read:";
    cin.getline(name, 101);
    nam=st(name);
    cout<<"\nName="<<name;
    cout<<"\nNam="<<nam<<"\n";

    fin.open(nam, ios::in);
    cout<<"\nDisplaying file data.";
    while(!fin.eof())
    {
        fin.get(ch);
        cout<<ch;
    }
    fin.close();
    return 0;
}
