from datetime import datetime

def prime2(num):
    print("\n\nMethod 2")
    print("Printing all primes from 2 to ", num)
    now=datetime.now().time()
    print("Start at :", now)
    primes=0
    i=2
    while(i<=num):
        j=2
        factor=2
        while(j<=i/2):
            if(i%j==0):
                factor=factor+1
            j=j+1
        
        if(factor==2):
            primes=primes+1
        i=i+1
    
    print("Total primes =", primes)    
    now=datetime.now().time()
    print("End at :", now)
    
def prime1(num):
    print("\n\nMethod 1")
    print("Printing all primes from 2 to ", num)
    now=datetime.now().time()
    print("Start at :", now)
    
    primes=0
    numbers=[1]
    for i in range(num):
        numbers.append(1)
    
    for i in range(2, num+1):
        if numbers[i]==1:
            j=2*i
            while(j<=num):
                numbers[j]=0
                j=j+i
    
    for i in range(2,num+1):
        if numbers[i]==1:
            primes=primes+1
    
    print("Total primes =", primes)    
    now=datetime.now().time()
    print("End at :", now)
    print()

def prime3(num):
    for i in range(2, num+1):
        fails = True
        for j in range(2, i):
            if not i%j:
                fails = False
                break
        if fails:
            print(i)
num=int(input("Enter range for prime :"))
prime3(num)
