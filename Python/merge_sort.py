def merge_sort(input_array):
    """ Divide and sort given array. """
    n = len(input_array)
    """ If array length is one, means it cannot be divided further.
        Else, divide it into right and left halves. """
    if n <= 1:
        return
    else:
        mid = n/2 # find the middle index of the input_array
        i = 0
        left_half = []
        right_half = []
        for i in range(mid):
            left_half.append(input_array[i])
        for i in range(mid,len(input_array)):
            right_half.append(input_array[i])
        merge_sort(left_half)
        merge_sort(right_half)
        merge(left_half,right_half,input_array)
    pass

def merge(left_array, right_array, combined_sorted):
    """ Get two sorted arrays and combine them into larger sorter array. """
    n_l = len(left_array)
    n_r = len(right_array)
    i = 0
    j = 0
    k = 0
    while i < n_l and j < n_r:
        if left_array[i] <= right_array[j]:
            combined_sorted[k] = left_array[i]
            i += 1
        else:
            combined_sorted[k] = right_array[j]
            j += 1
        k += 1
    while i < n_l:
        combined_sorted[k] = left_array[i]
        i += 1
        k += 1
    while j < n_r:
        combined_sorted[k] = right_array[j]
        j += 1
        k += 1

# Test merge sort
l = [14,9,8,7,6,5,4,3,2,1]
m = []
n = [1,5,6,11,9]
merge_sort(l)
print l
merge_sort(m)
print m
merge_sort(n)
print n
