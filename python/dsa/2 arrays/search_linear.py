# search for asked value in a linear manner

def search_linear(myList, val):
    for i in range(len(myList)):
        if myList[i] == val:
            return i
    return -1

arr = [3, 7, 2, 9, 5]
targetVal = 9
print(search_linear(arr, targetVal))