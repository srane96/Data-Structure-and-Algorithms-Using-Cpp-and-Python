""" Given an array of integer values and a specific number, find the indices of
    two numbers such that their sum is equal to the given number. """
def two_int_sum(input_array, sum):
    """ takes input_array and returns an array of indices of two numbers.
        Returns None if no two such numbers are present."""
    input_dict = {} # create an input dictionary
    """ Create a dictionary of type <value, its index>
        So that index can be accessed by value. """
    for i in range(len(input_array)):
        """ If a sum - current number is present in the dictionary then we have
            found the solution. Otherwise add current number for future use."""
        if (sum - input_array[i]) in input_dict:
            return [i,input_dict[sum-input_array[i]]]
        else:
            input_dict[input_array[i]] = i
    return None


# Function test
inp_array = [1,2,3,5,6]
# Should be [2,1]
print(two_int_sum(inp_array,5))
# Should be None
print(two_int_sum(inp_array,16))
