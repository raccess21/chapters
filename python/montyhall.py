import random
def sim1(num):
    choices = [0, 0]
    counter = [0, 0, 0]
    for i in range(num):
        doors = [0, 1, 2]
        p = random.choice(doors)
        counter[p] += 1
        ch1 = random.choice(doors)
        doors2 = []
        for door in doors:
            if door != p and door != ch1:
                doors2.append(door)
        doors.remove(random.choice(doors2))
        doors.remove(ch1)
        ch2 = doors[0]
        if p == ch1:
            choices[0] += 1
        else:
            choices[1] += 1
    print("Occurence of win")
    print(f'Staying with original door: {choices[0]}  ( P(E): {choices[0]/num} )')
    print(f'Choosing the "other" door: {choices[1]}   ( P(E): {choices[1]/num} )')
    print("doors counter  ", counter)
   
num = int(input("Enter simulation number: "))
sim1(num)
