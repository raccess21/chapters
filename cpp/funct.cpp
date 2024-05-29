#include<iostream>
#include<string>
using namespace std;

int main()
{
    char text[30], tr='t';
    cout<<"\nEnter name:";
    cin.getline(text,30,'t');
    cout<<"\nName="<<text;
    return 0;
}
