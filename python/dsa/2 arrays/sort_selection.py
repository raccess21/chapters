#  finds the lowest value in an array and moves it to the front of the array.
def selection_sort(myList):
    n = len(myList)
    
    for times in range(n-1):
        print(myList)
        mindex = times
        for i in range(times+1, n):
            if myList[i] < myList[mindex]:
                mindex = i
        myList[times], myList[mindex] = myList[mindex], myList[times]
    return myList


myList =  [ 7, 12, 9, 11, 3] 
print(selection_sort(myList))