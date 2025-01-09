def lowest(myList):
    minVal = myList[0] 
    for i in myList[1:]:
        if i < minVal:
            minVal = i
    
    return minVal


def lowest_py(myList):
    return min(myList)


print(lowest([1,2,5,3]))
