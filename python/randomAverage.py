import random
count=0
sum=0
while(count<100):
    num=random.randrange(1,100)
    if((num/2)==0):
        num=num+10
    if((num/2)!=0):
        num=num+20
    sum=sum+num
    count=count+1

print(float(sum/count))

#task generate distribution of random values
