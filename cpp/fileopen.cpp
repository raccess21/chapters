#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main()
{
    char str[31];
    int len;
    ofstream fout;

    cout<<"\nEnter file path:";
    cin>>str;
    len=strlen(str);
    //str[len]=NULL;
    fout.open(str, ios::out);
    fout<<"success";
    fout.close();
    return 0;
}
