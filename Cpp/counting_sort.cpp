#include <iostream>
#include <vector>
#include <algorithm>
// Print the given array
void printArray(std::vector<int> &arr) {
  for (int i=0; i<arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
// function to perform the counting sort
void countingSort(std::vector<int> &arr) {
  // let's assume that array does not contain any integer greater than 99
  int* count = new int[100];
  for(int i:arr) {
    count[i] += 1;
  }
  std::vector<int> ans;
  for(int i=0; i<100;i++) {
    while(count[i] != 0) {
      ans.push_back(i);
      count[i] -= 1;
    }
  }
  printArray(ans);
}

int main() {
  std::vector<int> arr{1,2,4,3,5,2,5,2,1,8};
  countingSort(arr);
}
