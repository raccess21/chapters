
def search_binary(myList, val):
    left = 0
    right = len(myList) - 1

    while left <= right:
        mid = (left + right) // 2
        
        if val == mid:
            return mid
        elif val < myList[mid]:
            right = mid - 1
        else:
            left = mid + 1

    return -1

arr = [3, 7, 2, 9, 5]
targetVal = 2
print(search_binary(arr, targetVal))