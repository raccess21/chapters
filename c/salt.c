#include <stdio.h>

int main()
{
	char pas[101], res[105], salt[]="abc";
	char *p = &pas[0];
	
	int i=0, j=0;
	
	printf("Enter password: ");
	scanf("%s", p);
	
	for(; pas[i]!='\0'; i++)
		res[i] = pas[i];
	
	for(; salt[j]!='\0'; j++)
		res[i+j] = salt[j];
	
	res[i+j] = '\0';
	
	printf("Salted phrase is : %s", res);
}
