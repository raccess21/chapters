# The word 'Bubble' comes from how this algorithm works, it makes the highest values 'bubble up'
def bubble_sort(myList):
    n = len(myList)
    
    for times in range(n - 1):
        swapped = False
        for i in range(n - times - 1):
            if myList[i] > myList[i+1]:
                swapped = not swapped
                temp = myList[i]
                myList[i] = myList[i+1]
                myList[i+1] = temp
        if not swapped:
            break
    
    return myList


def bubble_sort_py(myList):
    
print(bubble_sort([1,2,5,3]))
