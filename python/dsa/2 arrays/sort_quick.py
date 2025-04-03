# takes an array of values, 
# chooses one of the values as the 'pivot' element
# moves the other values so that lower values are on the left of the pivot element, 
# and higher values are on the right of it.
def partition(array, low, high):
    pivot = array[high]
    i = low - 1

    for j in range(low, high):
        if array[j] <= pivot:
            i += 1
            array[i], array[j] = array[j], array[i]

    array[i+1], array[high] = array[high], array[i+1]
    return i+1

def quick_sort(array, low=0, high=None):
    if high is None:
        high = len(array) - 1

    if low < high:
        pivot_index = partition(array, low, high)
        quick_sort(array, low, pivot_index-1)
        quick_sort(array, pivot_index+1, high)


myList =  [ 7, 12, 9, 11, 3] 
print(quick_sort(myList))