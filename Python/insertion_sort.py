def insertion_sort(input_array):
    """ This algorithm is based of the assumption that left most part of
    the array is sorted. Then we start from next element and place it
    at the appropriate position in the sorted array. """
    for i in range(1,len(input_array)):
        key = input_array[i]
        j = i - 1
        while j >= 0 and key < input_array[j]:
            input_array[j+1] = input_array[j]
            j -= 1
        input_array[j+1] = key

# Test insertion sort method
l = [9,8,12,6,55,5,4,3,2,1]
insertion_sort(l)
n = [11,5,6,11,9]
insertion_sort(n)
print(l)
print(n)
