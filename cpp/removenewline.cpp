#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    char filepath[]="C:/rahul/CodeBlock/testalgo.txt";
    ofstream fout;
    fout.open(filepath, ios::app|ios::out);

    fout.seekp(-2, ios::cur);
    fout<<"\0\0";
    return 0;
}
