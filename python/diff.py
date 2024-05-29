import os
os.system('clear')
num= int(input("Enter a number : "));     #input integer number
Diff= int(input("Enter a difference :"));   #input integer difference

i=1
square=0
sum=0
while(i<=num):
    square=i*i
    sum+=square
    print(f'({i} : {square}),', end='   ')
    i+=Diff
  
'    print("Square of", i, "is", i*i, sep=' ')'
    
print(f"Sum of series is {sum}");           #print formatted message with sum
