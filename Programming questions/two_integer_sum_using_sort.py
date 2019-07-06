""" For a given array S and a number sum, find two integers n1 and n2 such that
    n1 + n2 = sum. """
def two_int_sum(input_array, sum):
    """ In this method I am first sorting an array and applying min-max
        algorithm. """
    input_array_sorted = sorted(input_array)
    left = 0
    right = len(input_array_sorted) - 1
    while left < right:
        if input_array_sorted[left] + input_array_sorted[right] == sum:
            return [input_array_sorted[left], input_array_sorted[right]]
        elif input_array_sorted[left] + input_array_sorted[right] < sum:
            left += 1
        else:
            right -= 1
    return None

# Test the Code
print(two_int_sum([3,3,3,2,6,5,4],5))
