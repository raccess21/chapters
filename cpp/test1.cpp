#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    char ch[50];

    fin.open("C:/rahul/CodeBlock/testalgo.txt", ios::in);
    fout.open("C:/rahul/CodeBlock/testalgoo.txt", ios::out);

    while(!fin.eof())
    {
        fin.getline(ch, 50, ',');
        if(ch[0]=='\0')
            fout<<"0,";
        else
        if(ch[0]=='\n')
            fout<<"0\n";
        else
            fout<<ch<<",";
    }

    fin.close();
    fout.close();
    return 0;
}
