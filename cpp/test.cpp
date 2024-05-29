#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream fin1;
    char ch='y', text[10];
    int i=1, num=0;

    fin1.open("C:/rahul/CodeBlock/testalgo.txt", ios::in);

    cout<<"\nFile1 data\n";
    cout<<"\nEnter1(y/n):";
    cin>>ch;

    while(!fin1.eof() && ch!='@')
    {
        fin1>>num;
        cout<<"\nEntry "<<i<<"="<<num;
        i++;
        fin1.get(ch);
    }

    fin1.seekg(0);
    i=1; ch='y';
    while(!fin1.eof())
    {
        fin1.getline(text, 10, ',');
        cout<<"\nEntry "<<i<<"="<<text;
        i++;
    }
    return 0;
}
