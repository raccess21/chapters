import os
os.system('cls')
print("Enter a +ve integer:", end=" ")
number=input()
num=int(number)

oddc=evenc=max=0
while(1):
    print(num, end="")
    if(max<num):
        max=num

    if((num%2)==0):
        num=num/2
        num=int(num)
        evenc=evenc+1
        print("**", end="")
    else:
        num=(num*3)+1
        oddc=oddc+1
        print("*", end="")

    print("  ->  ", end="")
    if(num==1):
        break

print("1")
oddc=oddc+1

print("\nCurrently queried :", number)
print("Max value reached :", max)
print("Even number count :", evenc)
print("Odd number count  :", oddc)
print("Total jumps taken :", evenc+oddc)
