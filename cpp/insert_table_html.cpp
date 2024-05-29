#include "iostream"
#include "fstream"
#include "C:/rahul/CodeBlock/custom.cpp"
using namespace std;

int main()
{
	char ch='1', table_inserter='$', text[1001];
	char filepath[3][101];
	ifstream fin1, fin2;
	ofstream fout;

	fin1.open("C:/rahul/html/table/test.html", ios::in);
	fin2.open("C:/rahul/html/table/2203outer12.txt", ios::in);
	fout.open("C:/rahul/html/table/result.html", ios::out);

	while(!fin1.eof())
	{
	    fin1.get(ch);
		if(ch==table_inserter)
            break;
		fout<<ch;
	}

	int cells=count_cell(fin2, text), i;
    char rowdata[cells][201];
    fin2.seekg(0);
    fin2.getline(text, 1001, '\n');
    csv2cell(text, rowdata);

    //------------table head printing-----------
    fout<<"\n<table>\n<tr>";
    for(i=0; i<cells; i++)
        fout<<"<th>"<<rowdata[i]<<"</th>";
    fout<<"</tr>";

	while(!fin2.eof())
    {
        fin2.getline(text, 1001, '\n');
        csv2cell(text, rowdata);

        //-----------table data print----------
        fout<<"\n<tr>";
        for(i=0; i<cells; i++)
            fout<<"<td>"<<rowdata[i]<<"</td>";
        fout<<"</tr>";

    }
    fout<<"\n</table>";

    while(1)
	{
	    fin1.get(ch);
		if(fin1.eof())
            break;
        fout<<ch;
	}

	fin1.close();
	fin2.close();
	fout.close();
	return 0;
}
