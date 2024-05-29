#include <stdio.h>
#include <string.h>


void swap(char *num)
{
	unsigned int len = strlen(num);
	
	int temp;
	for(int i = 0; i<len/2; i++)
	{
		temp = num[i];
		num[i] = num[len-i-1];
		num[len-i-1] = temp;
	}
}


void input(char mes[], char *num)
{
	printf("%s", mes);
    scanf("%s", num);	
}


void iprint(char mess[], char *num)
{
	printf("%s%s", mess, num);	
}


int icom(char *numl, char *nums)
{
	int lenl = strlen(numl);
	int lens = strlen(nums);
	
	if(lenl > lens)
		return lenl;
	else if(lenl < lens)
		return -1*lens;
	else 
	{	
		for(int i = 0; i<lenl; i--)
		{
			if(*(numl+i) > *(nums+i))
				return lenl;
			else if(*(numl+i) < *(nums+i))
				return -1*lenl;
		}
	}
	return 0;
}


char* iadd(char *numl, char *nums)
{
	if (strlen(numl) < strlen(nums))	
	{
		char *tmp = nums;
		nums = numl;
		numl = tmp;
	}
	
	unsigned long int size = strlen(numl) + 1;
	char res[size];
	char *re = &res[0];
	unsigned long int i;
	unsigned int carry, r;
	
	carry = r = 0;
	
	swap(nums);
	swap(numl);
	
	for(i = 0; nums[i] != '\0'; i++)
	{
		r = ((int) * (nums+i) - 48) + ((int) * (numl+i) - 48) + carry;
		res[i] = (r % 10) + 48;
		carry = r / 10;
	}
	
	
	for(; numl[i] != '\0'; i++)
	{
		r = ((int) * (numl+i) - 48) + carry;
		res[i] = (r % 10) + 48;
		carry = r / 10;
	}
	
	if(carry != 0)
		res[i++] = carry + 48;
	
	res[i] = '\0';
	
	swap(res);
	swap(nums);
	swap(numl);	
	return re;
}


char* ipro2(char *numl, char *nums)
{
	int big = icom(numl, nums);
		
	if(big < -1)
	{
		char *tmp = nums;
		nums = numl;
		numl = tmp;
	}
	
	unsigned long int sizes, sizel;
	sizes = strlen(nums);
	sizel = strlen(numl);
	char res[sizes + sizel];
	char rest[sizel + sizes];
	res[0] = '0';
	res[1] = '\0';
	char *re = &res[0];
	swap(numl);
	swap(nums);
	
	for(int i=0; nums[i]!='\0'; i++)
	{
		unsigned short int carry, r;
		carry = r = 0;
		
		unsigned int j = 0;
		printf("\n%c", nums[i]);
		for(; j<i; j++)
		{
			rest[j] = 48;
			printf("0");
		}
				
		for(int k=0; numl[k]!='\0'; j++, k++)
		{
			r = (int)(*(nums+i)-48) *  (int)(*(numl+k)-48) + carry;
			printf("\t%d", r%10);
			carry = r/10;
			rest[j] = (r % 10) + 48;	
		}
		
		if(carry != 0)
			rest[j++] = carry + 48;
		rest[j] = '\0';
		swap(rest);
		
		printf("\t%s", rest);
		re = iadd(&res[0], &rest[0]);
		printf("\t%s", re);
	}
	printf("\nResult is : %s", re);
}

char* ipro(char *numl, char *nums)
{
	int big = icom(numl, nums);
	
	if(big < -1)
	{
		char *tmp = nums;
		nums = numl;
		numl = tmp;
	}
	
	char res[1001], rest[1001];
	char *re = &res[0];
	res[0] = '\0';
	
	if(big == 0)
		return re;
	
	//char res[strlen(numl) + strlen(nums)];
	
	long unsigned int r, i, j, k;
	
	swap(numl);
	swap(nums);
	int nume, carry;
	nume = carry = i = j = k = 0;
	
	for(i=0; nums[i]!='\0'; i++)
	{	
		
		nume = (int)*(nums+i) - 48;
		
		for(k=0; k<i; k++)
			rest[k] = 48;
			
		for(int j=0; numl[j]!= '\0'; j++)
		{
			r = ((int) *(numl+j) - 48) * nume + carry;
			rest[j+k] = (r % 10) + 48;
			carry = r/10;
		}
		
		if(carry != 0)
			rest[j++] = carry + 48;
	
		rest[j] = '\0';
		swap(rest);
		printf("\n%ld. %s", i, rest);
		re = iadd(&res[0], &rest[0]);
	}
	
	swap(numl);
	swap(nums);
	return re;	
}


char* isub(char *numl, char *nums)
{
	int big = icom(numl, nums);
	
	if(big == -1)
	{
		char *tmp = nums;
		nums = numl;
		numl = tmp;
	}
	
	char res[strlen(numl)+1];
	char *re = &res[0];
	unsigned int i;
	
	int quo, r;
	
	quo = r = 0;
	
	swap(nums);
	swap(numl);
	
	for(i = 0; nums[i] != '\0'; i++)
	{
		r = ((int) * (numl+i) - 48) - ((int) * (nums+i) - 48);
		if(r < 0)
		{
			r += 10;
			*(numl+i+1) -= 1;
		}
		res[i] = r;
		
		res[i] = (r % 10) + 48;
		quo = r / 10;
	}
	
	
	for(; numl[i] != '\0'; i++)
	{
		r = ((int) * (numl+i) - 48) + quo;
		res[i] = (r % 10) + 48;
		quo = r / 10;
	}
	
	if(quo!=0)
	{
		res[i] = quo + 48;
		i += 1;
	}
	res[i] = '\0';
	
	swap(res);
	swap(nums);
	swap(numl);	
	return re;
}

int main()
{
    char num1[1001], num2[1001];
    input("Enter num1: ", &num1[0]);
    input("Enter num2: ", &num2[0]);

	ipro2(num1, num2);	
	return 0;
}


