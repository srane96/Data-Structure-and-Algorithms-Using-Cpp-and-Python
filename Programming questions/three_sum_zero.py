""" Given an array S of unique integers, find three numbers n1, n2 and n3 such that
    n1 + n2 + n3 = 0. This pair should be unique. """
def three_sum(input_array):
    """ return a list of triplets."""
    answer_list = []
    sorted_array = sorted(input_array) # sort the given array
    for i in range(0, len(sorted_array) - 2):
        start = i + 1
        end = len(sorted_array) - 1
        """ Similar to min-max algorithm. """
        while (start < end):
            if sorted_array[i] + sorted_array[start] + sorted_array[end] == 0:
                answer_list.append([sorted_array[i], sorted_array[start], sorted_array[end]])
                start += 1
                end -= 1
            elif sorted_array[i] + sorted_array[start] + sorted_array[end] < 0:
                start += 1
            else:
                end -= 1
    return answer_list

# Test three sum
print(three_sum([1,2,-3,11,6,7,9,-1,-5]))
