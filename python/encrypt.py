'''
import random
a = random.randint(3, 9999)
b= random.randint(3, 83901)
c= a*b
print("First Number= ", a)
print("Second Number= ", b)
print("Sum of a & b Number= ", c)
'''
'''
IMPORTANT CODE FOR PRIME
a= int(input("Enter a Num= "))
factor= 0
for i in range (1, a+1):
	if a % i ==0:
		factor=factor+1
		
if factor > 2:		
	print("Not prime")
else:
	print("Prime")
'''
def generate_prime(digits):
	a = random.randint(10**digits, 10**(digits+1))
	while True:
		factor= 0
		for i in range (1, a+1):
			if a % i == 0:
				factor=factor+1
			
			
		if factor > 2:	
			print(a,"is not a prime no.")
			a = a+1
		else:
			print("Your Prime No. is ", a)
			return a


import random

a = generate_prime(7)			
b = generate_prime(7)

c= a*b
print("First Number= ", a)
print("Second Number= ", b)
print("Sum of a & b Number= ", c)

