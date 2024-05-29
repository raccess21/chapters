from random import randint

def dice():
    val = 100
    count = [0, 0, 0, 0, 0, 0]
    diff = suml = []

    for _ in range(val):
        sum = 0
        for _ in range(100):
            n = randint(1,6)
            count[n-1]+=1
            sum += n
        suml.append(sum)

    print(sorted(suml))
    print('\n\n')
    print(count)


dice()