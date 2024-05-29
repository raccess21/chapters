#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char filepathin[]="C:/rahul/CodeBlock/2203salrdy.txt";
    char filepathout[]="C:/rahul/CodeBlock/2203salrdy2.txt";
    unsigned int *pos, i=0;
    char *text, ch='y';
    ifstream fin;
    ofstream fout;
    cin.getline();
    fin.open(filepathin, ios::in);
    fout.open(filepathin, ios::out);

    while(!fin.eof())
    {
        pos=i;
        while(1)
        {
            fin.get(ch);
            if(ch!='y' && ch!='\n')
                text++=ch;
        }
    }

    fin.close();
    fout.close();
    return 0;
}
