# elements of array are sorted based on the individual digits of each element
# starting from least significant to the most

def sort_radix(myList):
    
    radix = [[] for i in range(10)]
    max_val = max(myList)
    exp = 1

    # exponents go from 10, 100, 1000, to isolate inidividual digits
    while max_val // exp > 0:
        while len(myList) > 0:
            val = myList.pop()
            radix[(val // exp) % 10].append(val)

        for bucket in radix:
            while(len(bucket) > 0):
                myList.append(bucket.pop())
        
        exp *= 10
    return myList
    
unsortedArr = [4, 2, 2, 6, 3, 3, 1, 6, 5, 2, 3]
print(sort_radix(unsortedArr))
