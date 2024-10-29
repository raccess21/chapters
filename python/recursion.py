def rec(k):
	if k > 0:
		res = k + rec(k-1)
		print(k, res)
	else:
		res = 0
	return res


def iprint(data):
	print('\n[')
	for d in data:
		t = str(type(d)).split(' ')[1]
		if t == "'int'>" or t == "'str'>":
			print(d, ",", end = "  ")
		else:
			iprint(d)
	print('\n]')
			
			
			
a = [1, ['a', 'b', [4, 5, 6], 'c'], 2, 3]
iprint(a)


