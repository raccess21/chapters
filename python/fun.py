def prime(num):
    factor=0
    i=1
    
    print("Factors of", num, "are   : ", sep=' ', end='')
    while(i<=num):
        if num%i==0:
            factor=factor+1
            print(i, end=', ')
        i=i+1
 
    print("\nTotal factors of", num, ":", factor, sep=' ')
    return factor

number=int(input("Enter input to check prime :"))
condition=prime(number)

print(number, "is ", end='')
if condition>2:
    print("a composite number.")
if condition==2:
    print("a prime number.")
if condition<2:
    print("neither prime nor composite.")