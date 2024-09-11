import random

max_num = int(input("Enter upper limit: "))
occuren = int(input("Enter picker occu: "))

sum = 0
for i in range(occuren):
    sum += random.randint(1, max_num)

print(f"Summation average is {sum}/{occuren} = {sum/occuren}")