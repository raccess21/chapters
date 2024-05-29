#include<iostream>
#include<fstream>
#include "C:/rahul/CodeBlock/custom.cpp"
using namespace std;

int main()
{
    char filepathout[]="C:/rahul/sqlite/testhtml.html";
    char filepathin[]="C:/rahul/sqlite/test.txt";
    char tag[]="row", text[5000];

    int i=0;

    ofstream fout;
    ifstream fin;

    fout.open(filepathout, ios::out);
    fin.open(filepathin, ios::in);
    int arg= count_cell(fin, text);

    int val;
    cout<<"\nEnter total num of columns to print:";
    cin>>val;

    if(val>arg)
    {
        val=arg;
        cout<<"\Entered column num is greater than max arguments";
        cout<<"\nReducing column num to max argument = "<<val;
    }

    int cell_regis[val];
    cout<<"\nEnter column num one by one:";
    for(i=0; i<val; i++)
    {
        cout<<"\nEnter cell number "<<i+1<<" :";
        cin>>cell_regis[i];
    }

    fout<<"<!DOCTYPE html>\n<head></head>\n<body>\n";
    fout<<"<table>\n";
    fin.seekg(0);
    while(!fin.eof())
    {
        char cell[arg][201];
        fin.getline(text, 5000, '\n');
        csv2cell(text, cell, ',');
        fout<<"<tr>\n";
        for(i=0; i<val; i++)
        fout<<"\t<td>"<<cell[cell_regis[i]]<<"</td>\n";
        fout<<"</tr>\n";
    }
    fout<<"</table>\n";
    fout<<"</body>\n</html>";
    fout.close();
    fin.close();
    return 0;
}
