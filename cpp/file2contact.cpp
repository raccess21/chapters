#include "C:/rahul/CodeBlock/custom.cpp"

int main()
{
    ifstream fin;
    ofstream fout;
    char text[501];
    fin.open("C:/rahul/contact/result.txt", ios::in);
    fputs("\nCreating contact file.", stdout);
    fout.open("C:/Users/Arun Kumar Das/Desktop/contacts3.txt", ios::out);
    cout<<"\nOpened output file";
    //cout<<"\nTotal entries : "<<tot;
    char ch;
    int i, j=1;
    while(!fin.eof())
    {
        ch='1'; i=0;
        fin.getline(text, 501, ',');
//        gotoxy(5,8);
        //status(i,tot);

        cout<<"\nContact:"<<j;
        fout<<"BEGIN:VCARD\nVERSION:2.1\nN:;";
        //gotoxy(5,10);
        cout<<"\tName:"<<text;
        fout<<'@'<<text<<";;;";

        while(1)
        {
            while(1)
            {
                fin.get(ch);
                if(ch==',' || ch=='\n' || fin.eof())
                    break;
                text[i++]=ch;
            }
            text[i]='\0';
            fout<<"\nTEL;VOICE:"<<text;
          //  gotoxy(5,11);
          //  cout<<"\tNumber:"<<text;
          if(ch=='\n' || fin.eof())
            break;
        }

        cout<<"Closing contact:"<<j++;
        fout<<"\nEND:VCARD\n";
    }


    fin.close();
    fout.close();
    return 0;
}
