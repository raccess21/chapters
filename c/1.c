#include <stdio.h>

int main()
{
    int n, sum = 0, i;
    for(i=0; i<3; i++)
    {
        printf("Enter num %d: ", i+1);
        scanf("%d", &n);
        sum+=n;
    }

    printf("Average is %d", (int)sum/i);
    return 0;
}