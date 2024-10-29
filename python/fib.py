def fib(val):
    n1 = 0
    n2 = 1
    sum = 1
    for i in range(val):
        sum = n1 + n2
        n1 = n2
        n2 = sum
    return sum

val = 50000000
