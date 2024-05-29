#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("C:/rahul/contact/Contacts.txt", ios::in);
    fout.open("C:/rahul/contact/Contacts2.txt", ios::out);

    int val, i=0, j;
    char  ch='1', tstart[]="BEGIN:VCARD", tend[]="END:VCARD";

    char text[10][201];
    while(!fin.eof())
    {
        val=1, j=0;
        cout<<"\n"<<++i;
        strcpy(text[j],"success");
        while(strcmp(text[j],tend)!=0 && !fin.eof())
        {
            fin.getline(text[j++], 201, '\n');
            if(text[j][3]=='@')
            val=0;
        }

        if(val==1)
        {
            for(int k=0; k<j; k++)
                fout<<text[k]<<"\n";
        }
    }
    return 0;
}
