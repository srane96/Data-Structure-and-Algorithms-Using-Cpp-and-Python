#include <iostream>
#include <vector>
#include <set>

// helper function to print the vector
void print_vector(std::vector<int> arr) {
  if(arr.size() == 0)
    std::cout << "[]";
  for(int i: arr) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}
// This method uses recursion
/*
Logic:
Start from empty subset.
At each step, you only have two options:
  1. either add current element to the subset and go to next element
  2. Don't add current element to the subset and go to next element
*/
void get_subsets(std::vector<int> arr, std::vector<int> subsets, int curr_index) {
  if(curr_index == arr.size())
    print_vector(subsets);
  else {
    // don't add current element to the subset and move forward
    get_subsets(arr, subsets, curr_index+1);
    // add current element to the subset and move forward
    subsets.push_back(arr[curr_index]);
    get_subsets(arr, subsets, curr_index+1);
    // all cases considered for the current element so remove it
    subsets.pop_back();
  }
}
int main() {
  std::vector<int> inp{5,10};
  std::vector<int> subsets;
  get_subsets(inp, subsets, 0);
}
