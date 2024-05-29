#include "C:/rahul/ecom/myntra/custom.cpp"
using namespace std;

int main()
{
    char filepath1[101], filepathlist[2][101];
    char filepathvar[101], filepathdata[101];
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

    listrdy<<filepathdataready<<", ";  //create list rdy files
    listfiles<<filepathvar<<", ";      //create list temp files
    listfiles<<filepathdata<<", ";
    listfiles<<filepathclass<<", ";
    listfiles<<filepathana<<", ";

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

    while(1)
    {
        fin.get(ch);
        if(ch=='\n')        //write variable names
            break;
        foutvar<<ch;
    }
    cout<<"\nVariable file ready to use at:"<<filepathvar;

    while(1)
    {
        fin.get(ch);
        if(fin.eof())           //write data
            break;
        foutdata<<ch;
    }
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

    foutdataready.open(filepathdataready, ios::out);    //,, to ,0,
    while(1)
    {
        findata.getline(zero, 500, ',');
        if(findata.eof())
        {
            if(zero[0]=='\0')
                foutdataready<<"0";
                else
                    foutdataready<<zero;
            break;                  //code to replace
        }
        else if(zero[0]=='\0')         //,, with ,0,
            foutdataready<<"0,";
        else
            foutdataready<<zero<<",";
    }
    cout<<"\nData file ready to use at:"<<filepathdataready;

    finvar.close();
    findata.close();
    foutdataready.close();
    foutclass.close();
    foutana.close();
    }

    listrdy.seekp(-1, ios::cur);
    listfiles.seekp(-1, ios::cur);
    listrdy<<'@';                  //to replace last newline
    listfiles<<'@';
    listrdy.close();
    listfiles.close();
    return 1;
}
