#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char filepath[101];
    char ch[]="a";

    strcpy(filepath, "C:/we/wed/wedc");
    for(; ch[0]<'e'; ch[0]++)
    {
        strcat(filepath, ch);
        cout<<"\n"<<filepath;
    }
    return 0;
}
