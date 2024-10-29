num = input("Input: ").split("+")
ans = 0

for t in num:
    a = t.split("*")
    if len(a) == 1:
        a.append('1')
    ans += int(a[0]) * int(a[1])

print(f"Result: {ans}")
