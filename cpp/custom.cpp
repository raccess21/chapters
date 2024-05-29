#include<iostream>
#include<fstream>
#include<windows.h>
#include<cstring>
#include<math.h>
#include "C:/rahul/CodeBlock/datatype.cpp"
using namespace std;

int gotoxy(int x, int y)
{
    COORD c;
    c.X=x;  c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    return 1;
}

int count_cell(ifstream &fin, char text[], char mode_char=',', char delim='\n')
{
    int cells=1, i=0;
    fin.getline(text, 5000, delim);
    while(text[i]!='\0')
    {
        if(text[i++]==mode_char)
            cells++;
    }
    return cells;
}

long int filesize(ifstream &fin, char test='\n')
{
    long int siz=0;
    char ch;
    while(!fin.eof())
    {
        fin.get(ch);
        if(ch==test)
            siz++;
    }
    fin.clear();
    fin.seekg(0);
    return ++siz;
}

int csv2cell(char text[], char cell[][201],  char delim=',')
{
    int i, j, k;
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
        return 1;
}

double char2num(char num[])
{
    long int n1=0;
    int leni=0, lenf=0, i=0, sign=1;       //length storage in j

    for(i=0; num[i]!='\0' && num[i]!='.'; i++,leni++);
    int j=leni;

    if(num[0]=='-')
    {
        i++;
        sign=-1;
        j--;
    }
    for(i=0; num[i]!='\0' && num[i]!='.'; i++)
        n1+=((num[i]-'0')*(pow(10, --j)));
    n1*=sign;
    if(num[leni]!='.')
        return (double)n1;

//---------------integer part end---------------------------//

    double n2=0;
    for(i=leni+1; num[i]!='\0'; i++,lenf++);
    j=1;
    for(i=leni+1; num[i]!='\0'; i++)
        n2+=((num[i]-'0')*(pow(10, -1*j++)));

    return (double)n1+n2;

//---------------fraction part end----------------------------//
}

int check()
{
    char ch;
    cout<<"\nPress y to continue(y/Y):";
    cin>>ch;
    if(ch=='y'||ch=='Y')
        return 1;
    else
        return 0;
}

int status(int iter, long int total)
{
    long int percent=0;
    percent= ((iter*100)/total);
    cout<<"Progress: "<<percent<<"% done";

    if(percent)
        return 1;
    else
        return 0;
}


int filetwin(ifstream &fin1, ifstream &fin2)
{
    char ch1, ch2;
    int trueval=1;

    fin1.seekg(0);
    fin2.seekg(0);
    while(!fin1.eof() && trueval==1)
    {
        fin1.get(ch1);
        fin2.get(ch2);
        if(ch1!=ch2)
        {
            trueval=0;
            goto skip;
        }
    }
    skip:

    return trueval;
}

int compare(char id1[11], char id2[11])
{
    int i=10;
    for(; i>1; i--)
    {
        if(id1[i]!=id2[i])
            return 0;
    }
    return 1;
}

int kmcompare(char id1[11], char id2[11])
{
    int i=9;
    for(; i>0; i--)
    {
        if(id1[i]!=id2[i])
            return 0;
    }
    return 1;
}

int skipline(ifstream &fin, int num, char test='\n')
{
    int i=0;
    char skip;
    cout<<"\nskipping:";
    fin.seekg(0);
    while(i<num)
    {
        fin.get(skip);
        if(fin.eof())
            break;
        if(skip=='\n')
        i++;
    }
    return 1;
}

int createfile(ifstream &fin, ofstream &fout, char ch='\0')
{
    char chi;
    if(ch=='\0')
    {
        while(!fin.eof())
        {
            fin.get(chi);       //write data
            fout<<chi;
        }
        return 1;
    }

    if(ch!='\0')
    {
        while(1)
        {
            fin.get(chi);
            if(chi==ch)        //write variable names
                break;
            fout<<chi;
        }
        return 1;
    }
    return 0;
}

int removechar(ifstream &fin, ofstream &fout, char test='\"', char ch_replace='\0')
{
    char ch;
    while(!fin.eof())
    {
            fin.get(ch);
            if(ch!=test)                //" removal
                fout<<ch;
                else
                fout<<ch_replace;
    }
    return 1;
}

int writezero(ifstream &fin, ofstream &fout)
{
    char zero[500];
    while(1)
    {
        fin.getline(zero, 500, ',');
        if(fin.eof())
        {
            if(zero[0]=='\0')
                fout<<"0";
                else
                    fout<<zero;
            break;                  //code to replace
        }
        else if(zero[0]=='\0' || zero[0]=='\n' || strcmp(zero, "null")==0)         //,, with ,0,
            fout<<"0,";
        else
            fout<<zero<<",";
    }
    return 1;
}

int filehandle()
{
    char filepath1[101], filepathlist[2][101];
    char filepathvar[101], filepathdata[101],   filepathdatatready[101];
    char filepathclass[101], filepathana[101], filepathdataready[101];
    char ch='y', zero[500], ch1[500], ch2[500];
    int len=0, word=0, checkval=0, files=0, i;
    ifstream fin, finvar, findata;
    ofstream foutvar, foutdata, foutdataready, foutclass, foutana;
    ofstream listrdy, listfiles;

    cout<<"\nEnter number of total files to process:";
    cin>>files;
    char filepath[files][101];
    cin.ignore(1,'\n');

    cout<<"\Enter filepath of source without .txt(C:/...):";
    for(i=0; i<files; i++)
    {
        cout<<"\nEnter filepath "<<i+1<<":";
        cin.getline(filepath[i],101);
    }

    for(i=0; i<files; i++)
        cout<<"\nDisplay filepath "<<i+1<<":"<<filepath[i];

    cout<<"\nEnter path of ready list without .txt:";
    cin.getline(filepathlist[0], 101);
    cout<<"\nEnter path of file list without .txt:";
    cin.getline(filepathlist[1], 101);

    strcat(filepathlist[0], ".txt");
    strcat(filepathlist[1], ".txt");
    listrdy.open(filepathlist[0], ios::out);
    listfiles.open(filepathlist[1], ios::out);

    for(i=0; i<files; i++)
    {
    strcpy(filepath1, filepath[i]);
    strcpy(filepathvar,filepath1);
    strcat(filepathvar,"var.txt");
    strcpy(filepathdata,filepath1);
    strcat(filepathdata,"dat.txt");
    strcpy(filepathdatatready,filepath1);
    strcat(filepathdatatready,"trdy.txt");
    strcpy(filepathdataready,filepath1);
    strcat(filepathdataready,"rdy.txt");
    strcpy(filepathclass,filepath1);
    strcat(filepathclass,"cls.txt");
    strcpy(filepathana,filepath1);
    strcat(filepathana,"van.txt");
    strcat(filepath1,".txt");

    cout<<"\nSource file path is:"<<filepath1;
    cout<<"\nVar file path is:"<<filepathvar;
    cout<<"\nData file path is:"<<filepathdata;
    cout<<"\nClass file path is:"<<filepathclass;
    cout<<"\nVar-ananlysis file path is:"<<filepathana;

    listrdy<<filepathdataready<<"\n";  //create list rdy files
    listfiles<<filepathvar<<"\n";      //create list temp files
    listfiles<<filepathdata<<"\n";
    listfiles<<filepathclass<<"\n";
    listfiles<<filepathana<<"\n";
    listfiles<<filepathdatatready<<"\n";

    openagain1:
    fin.open(filepath1, ios::in);      //source file
    foutvar.open(filepathvar, ios::out);    //variable list
    foutdata.open(filepathdata, ios::out);  //raw data file
    foutclass.open(filepathclass, ios::out);    //class creation
    foutana.open(filepathana, ios::out);    //approximate var-data analysis

    if(!fin && !foutvar && !foutdata && !foutclass && !foutana)
    {
        cout<<"\nError opening file.";
        cout<<"\nTo retry enter 'y'";
        checkval=check();
        if(checkval)
            goto openagain1;
            else
            {
                cout<<"\nError opening. Please relaunch.";
                exit(0);
            }
    }
    else
    {
        cout<<"\nCreation of files successful.";
        cout<<"\nWriting data.";
    }

    createfile(fin, foutvar, '\n');
    cout<<"\nVariable file ready to use at:"<<filepathvar;
    createfile(fin, foutdata);
    cout<<"\nData file ready to use at:"<<filepathdata;

    foutvar.close();
    foutdata.close();
    fin.close();

    openagain2:
    finvar.open(filepathvar, ios::in);  //openmode change for
    findata.open(filepathdata, ios::in);    //class analysis creation

    if(!finvar && !findata)
    {
        cout<<"\nError opening file.";
        cout<<"\nTo retry enter 'y'";
        checkval=check();
        if(checkval)
            goto openagain2;
        else
        {
            cout<<"\nError opening. Please relaunch.";
            exit(0);
        }
    }
    else
    {
        cout<<"\nOpenmode change successfull.";
        cout<<"\nWriting class and variable analysis...";
    }

    foutclass<<"#include<iostream>\n#include<fstream>";
    foutclass<<"\nusing namespace std;\nclass name\n{\npublic:";

    while(!finvar.eof())
    {                                      //declaration
        finvar.getline(ch1, 500, ',');         //class variables
        findata.getline(ch2, 500, ',');
        len=strlen(ch2)+1;
        //cout<<"\n"<<++word<<" "<<ch1<<"\t"<<len;
        foutclass<<"\n\tchar "<<ch1<<"["<<len<<"];";
        foutana<<ch1<<",";                //varanalysis keep var name
    }
    foutana.seekp(-1, ios::cur);      //replace last ',' with '@'
    foutana<<"@\n";                   //'@' to differentiate blocks

    foutclass<<"\n\n\tvoid readraw(ifstream &fin)";
    foutclass<<"\n\t{\n\t\tchar skip;";

    finvar.seekg(0);
    findata.seekg(0);
    while(!finvar.eof() && !findata.eof())   //writing
    {                                   //readraw function
        finvar.getline(ch1, 500, ',');
        findata.getline(ch2, 500, ',');
        len=strlen(ch2)+1;
        //cout<<"\n"<<++word<<" "<<ch1<<"\t"<<len;
        foutclass<<"\n\t\tfin.getline("<<ch1<<","<<len<<","<<"\',\');";
        foutana<<"\n"<<ch1<<"\t\t"<<ch2<<"\t:"<<len;
    }

    foutclass<<"\n\t}\n\n\tvoid display()\n\t{";

    finvar.seekg(0);
    findata.seekg(0);
    while(!finvar.eof())  //output
    {
        finvar.getline(ch1, 500, ',');
        findata.getline(ch2, 500, ',');
        //len=strlen(ch2)+1;
        //cout<<"\n"<<++word<<" "<<ch1<<"\t"<<len;
        foutclass<<"\n\t\tcout<<\"\\n"<<ch1<<" is :\"<<"<<ch1<<"; ";
    }

    foutclass<<"\n\t}\n\n\tvoid writeraw(ofstream &fout)\n\t{";

    finvar.seekg(0);
    while(!finvar.eof())           //writeraw()
    {
        finvar.getline(ch1,500,',');
        foutclass<<"\n\t\tfoutclass<<"<<ch1<<"<<\",\";";
    }

    foutclass<<"\n\t}\n};";

    cout<<"\n\nClass file ready to use at:"<<filepathclass;
    cout<<"\nVar analysis file ready to use at:"<<filepathana;

    findata.seekg(0);
    foutdataready.open(filepathdatatready, ios::out);
    removechar(findata, foutdataready, '\"');   //remove "

    foutdataready.close();
    findata.close();

    findata.open(filepathdatatready, ios::in);
    foutdataready.open(filepathdataready, ios::out);    //,, to ,0,
    writezero(findata, foutdataready);

    cout<<"\nData file ready to use at:"<<filepathdataready;

    finvar.close();
    findata.close();
    foutdataready.close();
    foutclass.close();
    foutana.close();
    }

    listrdy.seekp(-1, ios::cur);
    listfiles.seekp(-1, ios::cur);
    listrdy<<'\0';                  //to replace last newline
    listfiles<<'\0';
    listrdy.close();
    listfiles.close();
    return 1;
}


int deletefiles(char filepath[101])
{
    if(remove(filepath)!=0)
    {
        cout<<"\nError in deletion.";
        return 0;
    }
        else
        cout<<"\n"<<filepath<<" deleted.";
    return 1;
}

int deletefiles(char test='\n')
{
    char filepath[101];
    int val=0;
    char ch='y';
    ifstream fin;

    cout<<"\nEnter filepath to file list to delete files from,";
    cout<<"\nwithout .txt:";
    cin.getline(filepath, 101);
    strcat(filepath, ".txt");

    fin.open(filepath, ios::in);
    if(!fin)
        return val;

    while(!fin.eof() && ch=='y')
    {
        fin.getline(filepath, 101, test);
        cout<<"\n"<<filepath;
        if(remove(filepath)!=0)
            cout<<"\nError in deletion.";
        else
        {
            cout<<"\n"<<filepath<<" deleted.";
            val++;
        }
        cout<<"\nENter:";
        cin>>ch;
    }

    fin.close();
    return val;
}

