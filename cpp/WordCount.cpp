#include<fstream>
#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
    ofstream fin;
    fin.open("C:/rahul/CodeBlocks/tester.txt", ios::out);
    //char ch[100];
   // int word=0;

    if(!fin)
    {
        cout<<"\nerror:";
        exit(0);
    }

    cout<<"\nFile accessed, computing...";

    //if(ch1=='\n')
      //  cout<<"\nnewline";

    //while(i==1)
    //{
     //   fin<<"\nyo";

//        cout<<ch;
        /*if(ch==' ' || ch=='/n')
            word++;
        else if(ch=='.')
        {
            line++;
        }*/
      //  if(ch=='\n')
        //break;
    //}

    //cout<<"\nWord="<<word;
    //cout<<"\nChar="<<alpha;
    //cout<<"\nLine="<<line;

    cout<<"\nProgram success:";
//    cin>>ch;
    fin.close();
    return 0;
}
