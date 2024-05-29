def factoriali(num):
    pr=1
    for i in range(1,num+1):
        pr*=i
        i+=1
    return pr


def addi(num1, num2):
    return num1+num2


def lst_prime(num, con=1):
    numbers=[0]
    for i in range(num):
        numbers.append(1)
    
    for i in range(2, num+1):
        if numbers[i]==1:
            j=2*i
            while(j<=num):
                numbers[j]=0
                j+=i
    
    print("Printing all primes from 2 to ", num)
    for i in range(2,num+1):
        if numbers[i]==con  :
            print(f'{i}, ', end=' ')    
        i+=1
    
    primes=0
    for i in range(2,num+1):
        if numbers[i]==con:
            primes+=1
    return primes
    

def chk_prime(num):
    factor=1
    i=1
    while(i<=num/2):
        if(num%i==0):
            factor+=1
        i+=1
    return factor


def grint(num):
    if num>int(num):
        return int(num)+1


def chk_int(x):
    if x+x!=2*x:
        print('Please enter a natural number')
        return 0
    else:
        return 1


#returns pythagorean triplet of specified number
#in a list
def pytha3(x):
    if int(x)!=x:
        print('Please enter a natural number')
        return 0
    x= int(x)
    triples= [x]
    sq= x*x
    if x%2==0:
        sq/=4
        triples.append(int(sq-1))
        triples.append(int(sq+1))

    else:
        triples.append(int((sq-1)/2))
        triples.append(int((sq+1)/2))
    
    for i in range(3):
        if triples[i]==0:
            triples[i]='Triplet does not exist'
    return triples


#returns rational number as a list of two integers
def rational(num):
    list= num.split('/')
    if len(list)==1:
        list.append(1)
    else:
        if list[1]=='0':
            print("Not defined for this set of values")
            quit()
    
    for i in range(len(list)):
        list[i]= int(list[i].strip())
        
    return list


#force user to input integer
def get_int(message):
    while True:
        try:
            num= int(input(message))
        except ValueError:
            print("Invalid integer...")
        else:
            return num

