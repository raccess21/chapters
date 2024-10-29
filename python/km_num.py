def fac(num):
    sum = 1
    for i in range(1, num+1):
        sum*=i
    print("Sum=", sum)
    return sum

num = int(input("Enter a number: "))
tmp = num
sum = 0 
while(num>0):
    sum+= fac(num%10)
    num=int(num/10)

print("Sum=", sum)
if sum == tmp and tmp>0:
    print(f"{tmp} is Krishnamurty Number")
else:
    print(f"{tmp} is not Krishnamurty Number")
    