#include "C:/rahul/CodeBlock/custom.cpp"

int main()
{
    char ch='y';    // name[20], phone[10] ;
    int i=1;
    long int tot;
    ifstream fin;
    ofstream fout;

    puts("\nReady to access files");
    if(!check())
      return 0;

    fputs("\nOpening data file.", stdout);
    fin.open("C:/rahul/contact/result.txt", ios::in);
    fputs("\nCreating contact file.", stdout);
    fout.open("C:/Users/Arun Kumar Das/Desktop/contacts3.txt", ios::out);

    tot=filesize(fin);
    cout<<"\nTotal entries : "<<tot;

    fin.clear();
    fin.seekg(0);
    while(!fin.eof())
    {
        fin.get(ch);
        gotoxy(5,8);
        status(i,tot);
        if(ch=='$')
        {
            gotoxy(5,9);
            cout<<"Writing contact:"<<i;
            fout<<"BEGIN:VCARD\nVERSION:2.1\nN:;";

            gotoxy(5,10);
            cout<<"Name:";
            fin.get(ch);
            while(ch!=',')
            {
                    putchar(ch);
                    fout.put(ch);
                    fin.get(ch);
            }
        }

        if(ch==',')
        {
            fout<<";;;\nTEL;CELL:";
            gotoxy(5,11);
            cout<<"Number1:";
            fin.get(ch);
            while(ch!=':' && ch!='~')
            {
                putchar(ch);
                fout.put(ch);
                fin.get(ch);
            }
        }

        if(ch==':')
        {
            fout<<";;;\nTEL;HOME:";
            gotoxy(30,11);
            cout<<"Number2:";
            fin.get(ch);
            while(ch!='~')
            {
                putchar(ch);
                fout.put(ch);
                fin.get(ch);
            }
        }

        if(ch=='~')
        {
            gotoxy(5,12);
            cout<<"Closing contact:"<<i++;
            fout<<"\nEND:VCARD\n";
            fin.get(ch);
        }
    }

    fin.close();
    fout.close();
    return 0;
}

