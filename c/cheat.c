#include <stdio.h>
#include <math.h>

void get_marks(int, int*);
void print_marks(int, int*);
int diff(int, int*);
void update(int, int*);

int main()
{/*
	//code for user input commented until update function under testing
	//comment block status:healthy
    int total;
    printf("Enter total subjects: ");
    scanf("%d", &total);
    
    int marks[total+1];
    update(total, &marks[0]);
   */ 
    int test[]={20,50,100,100};
    update(3, &test[0]);
    return 0;
}


//update mark value
void update(int total, int *m)
{
	const int min = 33;
	int dif = diff(total, m), failc = 0, i;
 	
 	for(i=0; i<total; i++)
 		if (*(m+i)<min)
 			failc+=1;
 	
 	if (dif <= 0)
 		if (failc == 0)
 			printf("No need");
 		else
 			for(i=0; i<total; i++)
 				if (*(m+i)<min)
 					*(m+i) = min;
 		
 	else
 		printf("Updating");    
 		//code for smart update goes here   
}


//get marks and store as an array, marks[0] addr 
//passed as pointer
void get_marks(int total, int *m)
{
    int i=0;
    
    for(; i<total; i++)
    {
    	printf("Enter marks (subject %d): ", i+1);
    	scanf("%d", m+i);
    }
    
    printf("Enter maximum marks)   : ");
    scanf("%d", m+i);    
}


//print marks stored as an array
void print_marks(int total, int *m)
{   
    int i=0;
    printf("\n\n");
    for(; i<total; i++)
    	printf("Marks of subject %d is: %d\n", i+1, *(m+i));
    printf("Maximum marks is: %d\n", *(m+i));
}


//calc difference between desired total and actual total
int diff(int total, int *m)
{
	float per = 50.0, sum = 0.0;
	float sumd = *(m+total)*total*per/100;
	
	for(int i=0; i<total; i++)
		sum += *(m+i);
	
	return (int)round(sumd - sum);
}
