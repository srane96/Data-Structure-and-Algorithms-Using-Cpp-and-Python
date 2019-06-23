def binary_search_iterative(input_list, search_element):
    """ Iteratively search for search_element in the input_list. """
    start = 0
    end = len(input_list) - 1
    while start <= end:
        middle = (start + end) / 2
        if input_list[middle] == search_element:
            return middle
        elif search_element > input_list[middle]:
            start = middle + 1
        else:
            end = middle - 1
    return -1

# test function
list1 = [1,2,3,4,5,6,12]
i1 = binary_search_iterative(list1,1)
i3 = binary_search_iterative(list1,3)
i6 = binary_search_iterative(list1,6)
i15 = binary_search_iterative(list1,15)
print i1, i3, i6, i15
