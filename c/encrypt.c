#include <random.h>
#include <stdio.h>

long unsigned int generate_prime(long unsigned int digits)
{
	a = random.randint(10**digits, 10**(digits+1))
	while()
	{
		int factor= 0;
		for(int i=1; i<=a; a++)
			if (a % i == 0)
				factor=factor+1;
			
			
		if (factor > 2)	
			printf("%d is not a prime no.", a);
		else
		{
			print("Your Prime No. is %d", a);
			return a;
		}
	}
}

int main()
{
	long unsigned int a = generate_prime(7);
	long unsigned int b = generate_prime(7);
}
