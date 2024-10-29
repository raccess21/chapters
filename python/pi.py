import mpmath
from math import ceil
import sys

def fac(num):
    if num < 2:
        return 1
    else:
        res = 1
        for i in range(2, num+1):
            res *= i
        return res
    
def intInp(prompt):
    try:
        return int(input(prompt))
    except:
        print("Enter radius, precision and decimal points as numeric values..")
        sys.exit(0)

def tri():
    print("------\nTriangle algorithm")
    print("Converges toward pi for every additional triangle")
    rad = intInp("Enter radius of circle : ")
    num = ceil(intInp("Enter no of triangles  : "))
    if num < 3:
        num = 3
    pi = num * mpmath.sin(mpmath.radians(180/num))
    print(f"Value of PI  : {pi}\n")

def ramMod(num):
    print("------\nRamanujan Modular Equation algorithm")
    print("Converges toward pi for every additional iteration")
    
    sum = 0
    for k in range(num+1):
        sum += fac(4*k) * (1103 + 26390*k) / (mpmath.power(fac(k), 4) * mpmath.power(396, 4*k))
    sum *= 2 * mpmath.sqrt(2) / 9801
    print(f"Value of PI  :{1/sum}\n")

def chundowsky(num):
    print("------\nChundowsky Formula algorithm")
    print("Produces ~14 digits of pi for every iteration")
    
    sum = 0
    for k in range(num+1):
        sum += fac(6*k) * (13591409 + 545140134*k) / (fac(3*k) * mpmath.power(fac(k), 3) * mpmath.power(-640320, 3*k))
    sum *= mpmath.sqrt(10005) / 4270934400
    print(f"Value of PI  :{1/sum}\n")

def iterators():
    print("------\nIteration algorithms")
    num = ceil(intInp("Enter no of iterations: "))
    ramMod(num)
    chundowsky(num)

def main():
    dec = ceil(intInp("Enter decimal points result: "))
    mpmath.mp.dps = dec
    # tri()
    iterators()
    print("-----------------------\n\n")

if __name__ == '__main__':
    main()