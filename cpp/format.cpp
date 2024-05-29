#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main()
{
    fstream f;
    int i;
    f.open("C:/rahul/CodeBlock/testalgo.txt", ios::in|ios::out);
    char ch, chat[101];
    cout<<"\nopen file:";
    cin>>ch;

    f.gets(chat);
    cout<<chat;
    f.seekg(0);
    while(!f.eof())
    {
        cout<<ch;
        f.get(ch);

    }

    cout<<"\nEnd of file:";

    cout<<"\nclosing file";
    f.close();
    return 0;
}
