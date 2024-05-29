import mathi
import hello
import os
#os.system('clear')
#print("Factorial is ",mathi.factoriali(mathi.addi(int(input("Enter first number :")), int(input("Enter second number :")))))
#print("\nTotal primes in interval - ", mathi.lst_prime(int(input("Enter a number :"))))
#print('Greatest integer:', mathi.grint(float(input("Enter a decimal :"))))
#print("Pythagorean triplet is", mathi.pytha3(int(input("Enter a natural number :"))))

#name= input('What\'s your name? ')
#hello.hello(name.title())

'''for i in range(2,101):
    print(f'Pythagorean triplet of {i} : {mathi.pytha3(i)}')'''

#print(__name__)
#print(mathi.__name__)
#print(mathi.chk_int(input("Enter a number :")))
'''num=mathi.chk_prime(int(input('Enter a number :')))
if num==2:
    print('It is a prime.')
elif num>2:
    print('It is composite.')
else:
    print('neither prime nor composite')
'''

'''a='a'
while True:
    if a=='a':
        break
        continue
        print(a)
    else:
        print("s")

a='wer'
print(a.rjust(5, '0'))
'''


months = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December",
}

for i in range(len(months)):
    print(months[i])