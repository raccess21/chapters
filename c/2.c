#include <stdio.h>

int chk(char name[20])
{
    char usr[]="satya";
    int len=0, i;

    for(i=0; name[i]!='\0'; i++)
        len++;

    if (len>5)
        return 0;
    else
    {
        for(i=0; i<5; i++)
        {
            if(usr[i]!= name[i])
            return 0;
        }
    }

    return 1;
}


int memory()
{
    char test[922337203685477];
    printf("%s", test);
    return 0;
}
int main()
{
  /*  char name[20];

    printf("Enter name: ");
    scanf("%s", name);
    
    if (chk(name)==1)
        printf("\nWelcome");
    else
        printf("\nNot your pc");
*/
    memory();
    return 0;
}