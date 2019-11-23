#include <iostream>
#include <vector>
// Print the given array
void printArray(std::vector<int> &arr) {
  for (int i=0; i<arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
// implement bubble sort
void insertionSort(std::vector<int> &arr) {
  // start from each index and keep swapping until biggest element reaches the end
  for(int i=1; i<arr.size(); i++) {
   int curr = arr[i];
   int j = i-1;
   while(arr[j] > curr && j>=0) {
     arr[j+1] = arr[j];
     j -= 1;
   }
   arr[j+1] = curr;
  }
  std::cout << "Insertion sort: ";
  printArray(arr);
}
int main() {
  std::vector<int> arr{-1,2,4,-3,5,2,-5,2};
  insertionSort(arr);
}
