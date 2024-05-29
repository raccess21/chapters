#include<iostream>
#include<fstream>
#include<windows.h>
#include "C:/rahul/CodeBlock/custom.cpp"
using namespace std;

int main()
{
   ifstream fin1, fin2;
   int checkval=1;
   fin1.open("C:/rahul/ecom/var.txt", ios::in);
   fin2.open("C:/rahul/ecom/len.txt", ios::in);

   if(!fin1 && !fin2)
   {
       cout<<"\nError opening file.";
       exit(0);
   }
   checkval=filetwin(fin1, fin2);
   cout<<"\ncheckval="<<checkval;
   return 0;
}
