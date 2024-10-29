#include <iostream>
using namespace std;

int main()
{
	int num[5], i=0;
	char nam[5];
	

	for(i=0; i<5; i++)
	{
		cout<<"\nEnter num [<<"i"<<]: ";
		cin>>num[i];
	}
	
	for(i=0; i<5; i++)
		cout<<"\nNum [i] is : "<<num[i];
	
	cout<<"\nNum is "<<num;

	return 0;	
}
