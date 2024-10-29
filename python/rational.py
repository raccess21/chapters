import mathi

'''def multiply(n1, n2):
    return n1*n2

num1u=int(input("Enter numerator no1  :"))
num1d=int(input("Enter denominator no1:"))

if num1d==0:
    print("Not defined for this set of values")
    quit()

num2u=int(input("Enter numerator no2  :"))
num2d=int(input("Enter denominator no2:"))

if num2d==0:
    print("Not defined for this set of values")
    quit()

numu = num1u*num2u
numd = num1d*num2d

print(numu, '/', numd)
'''
'''

#transferred to mathi.py
def rational(num):
    list= num.split('/')
    if len(list)==1:
        list.append('1')
    else:
        if list[1]=='0':
            print("Not defined for this set of values")
            quit()
    
    for i in range(len(list)):
        list[i]= int(list[i])
    return list
'''


num1= mathi.rational(input("Enter num1: "))
num2= mathi.rational(input("Enter num2: "))
print((num1[0]* num2[0]), '/', (num1[1]* num2[1]))