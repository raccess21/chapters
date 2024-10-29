def main():
    num = int(input("Enter: "))
    pain1(num)


def pain1(num):
    prodl = [1, 0]
    prod = 1
    for i in range(1, num+1):
        prod *= i
        prodl[0] *= i
        if i % 10 == 0:
            prodl = count_0(prodl)
    
        print(i, ':', prod)
        print(i, ':', prodl[0], prodl[1])
        if prod != prodl[0]*(10**prodl[1]):
            print("Not ok")
        print()

    

def count_0(prod):
    if prod[0] == 0:
        return [0, 0]

    while(prod[0] % 10 == 0):
        prod[0] = int(prod[0]/10)
        prod[1] += 1
    
    return prod


main()
