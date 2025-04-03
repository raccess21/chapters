# fibonacci using recursion for nth term
def fib_recursion_n(n):
    if n <= 1:
        return 1-n
    return fib_recursion_n(n - 1) + fib_recursion_n(n - 2)


# fibonacci using loop for nth term
def fib_loop(n):
    if n <= 2:
        return n-1

    first, second = [0, 1]

    for i in range(2, n):
        res = first + second
        first = second
        second = res
    
    return res


for n in range(1, 10):
    # print(n, fib_recursion_n(n))
    # print(n, fib_loop(n))
    ...    