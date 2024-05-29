#include<iostream>
#include<fstream>
using namespace std;

int writezero(ifstream &, ofstream &);
int writezero2(ifstream &, ofstream &);
int writezero3(ifstream &, ofstream &);
int writezero4(ifstream &, ofstream &);

int main()
{
    char ch;
    int comma=0;
    ifstream fin;
    ofstream fout;
    fin.open("C:/rahul/ecom/myntra/2107rawfordata.txt", ios::in);
    fout.open("C:/rahul/ecom/myntra/testalgoo.txt", ios::out);
    writezero4(fin, fout);
  /*  if(!fin && !fout)
        cout<<"\nError opening file.";
    else
    {
        cout<<"\nprocessing";
        while(1)
        {
            fin.get(ch);
            if(fin.eof())
            {
                cout<<"\nEnd of file.";
                goto last;
            }
            else if(ch==',')
            {
                while(ch==',')
                {
                    fin.get(ch);
                    if(fin.eof())
                    {
                        fout<<",0";
                        cout<<"\nEnd of file";
                        goto last;
                    }
                    else if(ch=='\n')
                        fout<<",0\n";
                    else if(ch==',')
                        fout<<",0";
                    else
                    {
                        fout<<","<<ch;
                        break;
                    }
                }
            }
            else
                fout<<ch;
        }
    }
    last:
    fin.close();
    fout.close();*/
    return 0;
}

int writezero3(ifstream &fin, ofstream &fout)
{
    char ch[50];
    while(!fin.eof())
    {
        fin.getline(ch, 50 ,',');
        if(ch[0]=='\0')
            fout<<"0,";
        else if(ch[0]=='\n' && ch[1]=='\0')
            fout<<ch<<"0";
        else if(ch[0]=='\n')
            fout<<"0"<<ch;
        else
            fout<<ch<<',';
    }

    last:
    fin.close();
    fout.close();
    return 0;
}


int writezero(ifstream &fin, ofstream &fout)
{
    char ch='y';
    int comma=0;

    if(!fin && !fout)
        cout<<"\nError opening file.";
    else
    {
        cout<<"\nprocessing";
        while(1)
        {
            fin.get(ch);
            if(fin.eof())
            {
                cout<<"\nEnd of file.";
                goto last;
            }
            else
                if(ch!=',')
                fout<<ch;

            if(ch==',')
                comma++;
        }
    }

    last:
    fin.close();
    fout.close();
    return 1;
}

int writezero2(ifstream &fin, ofstream &fout)
{
    char ch='y', next='y';

    fin.seekg(0);
    while(1)
    {
        fin.get(ch);
        if(fin.eof())           //qwasedg,,,21wed,,,,2edf
            goto last;          //dfgvbn,45,,,,4trf,,,,

        if(ch!=',')             //1wefd,,,,,
            fout<<ch;
        else
        {
            fin.get(next);
            if(fin.eof())
            {
                fout<<ch<<"0";
                goto last;
            }
            else if(next=='\n')
                fout<<ch<<"0"<<next;
                else if(ch==',' && next==',')
                {
                    fout<<ch<<"0";
                    fin.seekg(-1, ios::cur);
                }
                else
                    fout<<ch<<next;
        }
    }

    last:
    fin.close();
    fout.close();
    return 1;
}
