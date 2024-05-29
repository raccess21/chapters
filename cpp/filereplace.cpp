#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream fi;
    char ch;
    int i=0;
    fi.open("C:/rahul/CodeBlock/file.txt", ios::in|ios::out);

    while(!fi.eof())
    {
        fi.get(ch);
        i++;
        if(ch=='n')
        {
            fi.seekp(i-1, ios::beg);
            while(ch!='\n')
            {
                fi<<'\0';
                fi.get(ch);
            }
        }
    }
    return 0;
}
