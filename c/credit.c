#include<stdio.h>
int check(char cr[]);

int main()
{
    char credit[17];

    printf("Enter card number: ");
    scanf("%s", &credit[0]);
    if(check(credit)==0)
    printf("Valid");
    else
    printf("Invalid");
    return 0;
}


int check(char credit[])
{
 int dif, i;
    dif = 0;

    for(i=0; credit[i]!='\0' ;i++)
    {
        if (i%2)
            dif+=2*((int)credit[i] - 48);    
        else
            dif-=(int)credit[i] - 48;
        printf("\n%d", i);    
    }
    
    return dif;
}