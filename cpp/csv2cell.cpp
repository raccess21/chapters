#include "C:/rahul/CodeBlock/custom.cpp"
using namespace std;

int main()
{
    char text[5000];
    int i=0, j ,k , arg=1;
    char filepath[]="C:/rahul/sqlite/2203outer12.txt";

    ifstream fin;
    fin.open(filepath, ios::in);

    fin.getline(text, 5000, '\n');
    while(text[i]!='\0')
    {
        if(text[i++]==',')
            arg++;
    }

    char ch='y';
    /*while(!fin.eof() && ch=='y')
    {
        fin.getline(text, 5000, '\n');
        char cell[arg][201];
        k=j=i=0;

        while(1)
        {
            if(text[i]=='\0')
            {
                cell[k][j]='\0';
                break;
            }
            else
                if(text[i]==',')
                {
                    cell[k][j]='\0';
                    k++;
                    j=0;
                }
                else
                    {
                        cell[k][j++]=text[i];
                    }
            i++;
        }

        for(i=0; i<arg; i++)
        cout<<"\n"<<cell[i];

        cout<<"\n\nEnter choice(y/n):";
        cin>>ch;
    }
    cout<<"\n"<<char2num("13.13")+char2num("12.12");
   */
    char cell[arg][201];

    while(!fin.eof() && ch=='y')
    {
    fin.getline(text, 5000, '\n');
    csv2cell(text, cell, ',');
    for(i=0; i<arg; i++)
        cout<<"\n"<<cell[i];

    cout<<"\nEnter choice (y/n) :";
    cin>>ch;
    }
    return 0;
}
