import os
os.system('cls')

print("Enter a +ve integer :", end="")
number=input()
num=int(number)
print("Entered number  :", number)
print("Querying number :", num, "   ->   ", end="")

maxi=oddc=evenc=0
while(1):
    if(maxi<num):
        maxi=num
    if(num%2==0):
        num=int(num/2)
        evenc=evenc+1
        print("**", end="")
    else:
        num=int(num*3+1)
        oddc=oddc+1
        print("*", end="")
   # num=int(num)
    print(num, end="")
    if(num==1):
        break
    print("   ->   ", end="")

print("\nMax value reached:", maxi)
print("Even jumps taken :", evenc)
print("Odd jumps taken  :", oddc)
print("Total jumps taken:", evenc+oddc)
