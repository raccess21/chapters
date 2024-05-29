#include<fstream>
#include<iostream>
using namespace std;

int main()
{
    char filepath1[]="C:/rahul/ecom/flipkart/raw/2203sal.txt";
    char filepath2[]="C:/rahul/ecom/flipkart/raw/2203salrdy2.txt";
    char ch;
    ifstream fin;
    ofstream fout;

    fin.open(filepath1, ios::in);
    fout.open(filepath2, ios::out);

    while(!fin.eof())
    {
            fin.get(ch);
            if(ch!='\"')
                fout<<ch;
    }
    fin.close();
    fout.close();

    return 0;

}
