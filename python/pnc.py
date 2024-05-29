def factorial(num):
	if num > 1:
		return num*factorial(num-1)
	else:
		return num
		
		
def main():
	print(factorial(3))
	

if __name__ == "__main__":
	main()
