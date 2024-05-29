#include<fstream>
#include<iostream>
using namespace std;

int main()
{
    char ch;
    ofstream fout;
    fout.open("C:/rahul/Writings/sat.csv", ios::out);
    fout<<"Let's do this.";
    fout.close();
    return 0;
}
