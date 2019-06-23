def binary_search_recursive(input_list, search_element, start, end):
    middle = (start + end) / 2
    if start > end:
        return -1
    if input_list[middle] == search_element:
        return middle
    elif input_list[middle] > search_element:
        return binary_search_recursive(input_list, search_element, start, middle-1)
    else:
        return binary_search_recursive(input_list, search_element, middle + 1, end)

# test function
list1 = [1,2,3,4,5,6,12]
i1 = binary_search_recursive(list1,1, 0, len(list1) - 1)
i3 = binary_search_recursive(list1,3, 0, len(list1) - 1)
i6 = binary_search_recursive(list1,6, 0, len(list1) - 1)
i15 = binary_search_recursive(list1,15, 0, len(list1) - 1)
print i1, i3, i6, i15
