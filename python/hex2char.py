def table():
	with open("hext.txt", "r") as filei, open("hex.txt", "w") as fileo:
		lines = filei.readlines()
		
		for line in lines:
			words = line.split('  ')
			if words[4] != '$$':
				print(words)
				fileo.write(f"{words[1].strip()}$${words[4].strip()}\n")
				

def decoder(phrase, sign = '-'):
	print()
	phrase = phrase.split(sign)
	with open("hex.txt", "r") as filei:
		hexlist = filei.readlines()
	
	for p in phrase:
		i=0
		t = ''
		while(i<len(p)-1):
			t = p[i] + p[i+1]
			
			for hexl in hexlist:
				if t.upper() == hexl.split("$$")[0]:
					print(hexl.split("$$")[1], end="")
					break	
			i += 2
		print(f"{sign}", end="")
			

def main():
	decoder("1f5376b1-ff06-405b-a484-3a63b0096dce-81b2592d-f963-42a2-adb3-9b0adf040766")
	
	
if __name__ == "__main__":
	main()
