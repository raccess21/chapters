from random import randint
import sys
import os

def main():
    mini = 1
    maxi = 10
    os.system("clear")
    print("Guess number game\nRULES.")
    print(f"1. Number is between {mini} and {maxi}")
    print(f"2. Number will shift (+1 or -1) after wrong guess.")
    print(f"3. Hint is your guess was higher or lower.")
    print(f"4. Press CTRL-C to give up.")
    game(randint(mini, maxi))


def game(num):
    print("\n----------------------BEGIN----------------------")
    print("----------------------^^^^^----------------------\n")
    tries = 0
    while True:
        try:
            n = int(input("Guess: "))
            tries += 1
            if n < num:
                print("Your guess was low.", end="")
            elif n > num:
                print("Your guess was high.", end="")
            else:
                print("You win")
                print("Total tries {tries}\nExiting...")
                break
        except ValueError:
            print("Not a number")
        except KeyboardInterrupt:
            sys.exit(f"\nAnswer is {num}\nTotal tries {tries}\nExiting...")
        else:
            print(" Changing number...")
            num = change(num)


def change(num):
    if num == 1:
        num += 1
    elif num == 10:
        num -= 1
    elif randint(0, 1) % 2 == 0:
        num += 1
    else:
        num -= 1
    return num


if __name__ == "__main__":
    main()
