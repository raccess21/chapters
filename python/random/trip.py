import random


def main():
    jumper = []
    maxi = 0
    for _ in range(1000):
        jumps = jump()
        jumper.append(jumps)
    print(sorted(jumper))
    print("Max jumps in a sequence:", max(jumper))


def jump():
    jumps = 0
    num = 0
    while True:
        if random.randrange(2) % 2 == 0:
            num += 1
        else:
            num -= 1

        jumps += 1
        if num == 0:
            return jumps


if __name__ == "__main__":
    main()
