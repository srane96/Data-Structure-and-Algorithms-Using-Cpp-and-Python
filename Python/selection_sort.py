def selection_sort(input_array):
    """ Get the smallest element and put it in the front. """
    for i in range(len(input_array)):
        smallest = input_array[i]
        smallest_ind = i
        for j in range(i+1,len(input_array)):
            if input_array[j] < smallest:
                smallest = input_array[j]
                smallest_ind = j
        if not smallest_ind == i:
            temp = input_array[i]
            input_array[i] = smallest
            input_array[smallest_ind]= temp

# Test selection sort
l = [9,8,12,6,55,5,4,3,2,1]
selection_sort(l)
print(l)
