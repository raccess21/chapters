#include <stdio.h>

//int length(int[]);
int main()
{	
	int len;
	printf("Enter len :");
	scanf("%d", &len);	
	
	int arr[len], i;
	for(i=0; i<len; i++)
	{
		printf("Enter num %d: ", i+1);
		scanf("%d", &arr[i]);
	}
	
	printf("%d", length(arr));
	return 0;
}

int length(int a[])
{
	return (int)(sizeof(a)/sizeof(int));
}
