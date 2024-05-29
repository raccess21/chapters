#include<iostream>
#include<fstream>
using namespace std;

class stu
{
    char name[30];
    char num[10];

public:
    int input()
    {
        cout<<"\nEnter name:";
        gets(name);
        cout<<"\nEnter number:";
        gets(num);
    }

    int read()
    {
            cout<<"\n";
            return 1;
    }

    int output()
    {
        cout<<"\nName:"<<name;
        cout<<"\nNumber:"<<num;
        return 1;
    }
};

int output(fstream &f)
{
    f.seekp(ios::end);
    f<<"\nName:";
    f<<"\nNumber:";
    return 1;
}

int main()
{
    //char *file="C:/rahul/CodeBlock/testalgo.txt";
    stu det;
    fstream f;
    int i=0; char ch='y';

    //cout<<"Enter file path:";
    //cin>>file;                   //input file path test

    f.open("C:/rahul/CodeBlock/testalgo.txt", ios::in);
  //  f.open(file, ios::in|ios::out);
    //det.input();
    //f.write((char*)&det, sizeof det);
    //det.output();
    //output(f);

    while(!f.eof())
    {
        f.get(ch);
        cout<<ch;
        if(ch=='\n')
            cout<<"\nnewline";
    }
    f.close();
    return 0;
}
