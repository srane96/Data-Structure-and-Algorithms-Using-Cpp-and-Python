def quick_sort(input_array, start, end):
    """ Select a pivot point and rearrange the elements lesser than the pivot to it's left side
    and elements larger than the pivot to it's right side. Continue doing this until array is
    sorted. In this case, pivot point is always selected as a last one."""
    i = start
    j = end # this represents the pivot point index
    while i < j:
        if input_array[i] > input_array[j]:
            tmp = input_array[i]
            input_array[i] = input_array[j-1]
            input_array[j-1] = input_array[j]
            input_array[j] = tmp
            j = j - 1 # shift the pivot index
        else:
            i += 1
    if not j == start: # if pivot did not reach the start
        quick_sort(input_array, start, j-1)
    if not j == end: # if pivot is not at the end
        quick_sort(input_array, j+1, end)

# Test insertion sort method
l = [9,8,12,6,55,5,4,3,2,1]
quick_sort(l,0,len(l)-1)
n = [11,5,6,11,9]
quick_sort(n,0,len(n)-1)
print(l)
print(n)
