#include "C:/rahul/CodeBlock/custom.cpp"

int main()
{
    char name1[500], text[50];
    ifstream fin;
    fstream f;
    char filepath[101];
    int vsize=0, pos;
    strcpy(filepath, "C:/rahul/contact/contact2.txt");
    fin.open(filepath, ios::in);
    strcpy(filepath, "C:/rahul/contact/result.txt");
    f.open(filepath, ios::out);

    /*while(!fin.eof())
    {
        fin.getline(name1, 500, '\n');
        vsize=strlen(name1);

        if(isdigit(name1[vsize-1])==0)
        {
            f<<name1;
            f<<"_";
        }
        else
            f<<name1<<"\n";
    }

    f.seekg(0);
    f.seekp(0);*/
    char ch, last='1';
    fin.get(ch);
    f<<ch;
    while(1)
    {
        last=ch;
        fin.get(ch);
        if(fin.eof())
            break;
        if(isdigit(last)==0 && isdigit(ch)==1)
        {
            f<<","<<ch;
        }
        else
            f<<ch;
    }
    fin.close();
    f.close();
    return 0;
}
