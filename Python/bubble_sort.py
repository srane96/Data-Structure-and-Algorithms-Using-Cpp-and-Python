def bubble_sort(input_array):
    """ Sort input_array in an ascending order. """
    for i in range(0, len(input_array)):
        for j in range(0,len(input_array) - i - 1):
            if input_array[j] > input_array[j+1]:
                tmp = input_array[j]
                input_array[j] = input_array[j+1]
                input_array[j+1] = tmp

# Test bubble sort
list1 = [71,18,9,5,6,2,4,3,1,11,44,22,55,66,666,551]
bubble_sort(list1)
print list1
