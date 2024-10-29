a = int(input("Enter number: "))

fac = []
suc = [-1, -1]
for i in range(1, a+1):
	if a%i == 0:
		fac.append(i)

print("Factors are:", fac)
for i in range(len(fac)-1):
	for j in range(i, len(fac)):
		if fac[i]*fac[j] == a:
			suc[0] = fac[i]
			suc[1] = fac[j]
			if suc[0]>1 and suc[1]>1:
				print("Numbers are", suc[0], "and", suc[1])
			break
			
