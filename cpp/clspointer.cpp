#include<iostream>
#include<fstream>
#include "C:/rahul/CodeBlock/custom.cpp"
using namespace std;

class data
{
  char name[21];
  int age;

  public:
      void input()
      {
          cout<<"\nEnter name";
          cin.getline(name, 21);
          cout<<"\nEnter age:";
          cin>>age;
      }

      void output()
      {
          cout<<"\nName is:"<<name;
          cout<<"\nAge is:"<<age;
      }
};

int main()
{
    data *det;
    ofstream fout;
    char ch='y';
    fout.open("C:/rahul/CodeBlock/testalgo.txt", ios::out);

    while(check()==1)
    {
        det->input();
        fout.write((char*) &det , sizeof(det));
    }

    fout.close();
    return 0;
}
