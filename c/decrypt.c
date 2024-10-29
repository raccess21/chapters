#include <stdio.h>

int main()
{

	long unsigned int a, num1, num2, i, j;
	
	printf("Enter number: ");
	scanf("%ld", &a);	 
	int fac[a];
	
	for(i=1; i<=a; i++)
	{
		if (a%i == 0)
			fac[i-1]=1;
		else
			fac[i-1]=0;
	}

	printf("Listing factors\n");	
	for(i=1; i<=a; i++)
	{
		if(fac[i-1] == 1)
			printf("%ld, ", i);
	}
		
	for(i=1; i<=a; i++)
	{
		if(fac[i-1] == 1)
			for(j=1; j<=a; j++)
				if(fac[j-1] == 1 && i*j == a)
				{
					printf("%ld and %ld\n", i, j);
					break;
				}			
	}
		
		
	}	
}
