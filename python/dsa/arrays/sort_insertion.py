# Insertion Sort algorithm uses 
# one part of the array to hold the sorted values
# the other part of the array to hold values that are not sorted yet.
def insertion_sort(myList):
    for i in range(1, len(myList)):
        print(myList)
        
        # select value for placement
        insert_index = i
        curr_val = myList[i]

        # compute where value fits in sorted part
        for j in range(i-1, -1, -1):
            if myList[j] > curr_val:
                myList[j+1] = myList[j]
                insert_index = j
            else:
                break
        
        # place value in it's place
        myList[insert_index] = curr_val
    
    return myList

myList =  [ 7, 12, 9, 11, 3] 
print(insertion_sort(myList))