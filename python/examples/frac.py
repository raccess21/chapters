# standard library for fraction calculations
# implemented in list approach
# (x/y) => [x, y] => x numerator, y denominator


# check if fraction is valid where num is [x, y]
# return num only if num is valid
def valid_frac(num):
    if 0 < len(num) < 3:
        if len(num) == 1:
            num.append("1")
        elif num[1] == "0":
            print("Denominator can't be zero")
            return False
    else:
        print("Invalid Fraction")
        return False

    try:
        for i in range(2):
            num[i] = int(num[i].strip(" "))
    except ValueError:
        print("Invalid Fraction")
        return False
    return num


# force user to enter a valid fraction X/Y
def get_frac(num="a"):
    while True:
        num = input("Enter number(x/y): ").split("/")
        if valid_frac(num):
            break
    return num


#simplify fraction 3/6 => 1/2
def simplify_frac(x):
    neg = 1
    if x[0] < 0:
        x[0] *= -1
        neg = -1

    #dex stores index value of smaller number of fraction
    if x[0] < x[1]:
        dex = 0
    else:
        dex = 1

    i = 2
    while i < x[dex] + 1:
        if x[0] % i == 0 and x[1] % i == 0:
            x[0] = x[0] / i
            x[1] = x[1] / i
        else:
            i += 1

    x[0] = neg * int(str(x[0]).split(".")[0])
    x[1] = int(str(x[1]).split(".")[0])
    return x


#inverse of fraction
def inverse_frac(num):
    if num[0] == 0:
        print("Multiplicative Inverse does not exsit")
        return False
    else:
        return [num[1], num[0]]


# multiply two fractions and return as list
def multi_frac(num1, num2):
    return simplify_frac(
        [
            num1[0] * num2[0]
            ,
            num1[1] * num2[1],
        ]
    )


#divide two fractions
def divide_frac(x, y):
    if inverse_frac(y):
        return simplify_frac(multi_frac(x, inverse_frac(y)))
    else:
        print("Zero Division Error")
        return False


#add two fractions
def add_frac(x, y):
    num_up = x[0] * y[1] + x[1] * y[0]
    return simplify_frac([num_up, x[1] * y[1]])


#subtract two fractions
def sub_frac(x, y):
    num_up = (x[0] * y[1]) - (x[1] * y[0])
    return simplify_frac([num_up, x[1] * y[1]])


#def pow_frac(x, y):



#print fraction 
def print_frac(x, prompt="Value is"):
    print(f"{prompt} {x[0]}", end="")
    if x[0] != 0 and x[1] > 1:
        print(f"/{x[1]}")
    else:
        print()

get_frac()

