# sort by counting occurence of each value in an array

def counting_sort(myList: list):
    max_val = max(myList)
    count = [0] * (max_val + 1)

    while len(myList) > 0:
        count[myList.pop()] += 1
        
    for i in range(len(count)):
        while(count[i] > 0):
            myList.append(i)
            count[i] -= 1
    
    return myList

unsortedArr = [4, 2, 2, 6, 3, 3, 1, 6, 5, 2, 3]
print(counting_sort(unsortedArr))
