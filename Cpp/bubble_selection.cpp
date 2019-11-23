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
void bubbleSort(std::vector<int> &arr) {
  // start from each index and keep swapping until biggest element reaches the end
  for(int i=0; i<arr.size()-1; i++) {
    for(int j=0; j<arr.size()-1;j++) {
      if(arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  std::cout << "Bubble sort: ";
  printArray(arr);
}

// implement selection sort
void selectionSort(std::vector<int> &arr) {
  // get the smallest element and put it in the front
  for(int i=0; i < arr.size(); i++) {
    int min = arr[i];
    int minIndex = i;
    for(int j=i; j < arr.size(); j++) {
      if(arr[j] < min) {
          min = arr[j];
          minIndex = j;
      }
    }
    // swap the element if smaller one is found
    if(minIndex != i) {
      int temp = arr[i];
      arr[i] = min;
      arr[minIndex] = temp;
    }
  }
  std::cout << "Selection sort: ";
  printArray(arr);
}
int main() {
  std::vector<int> arr{-1,2,4,-3,5,2,-5,2};
  bubbleSort(arr);
  selectionSort(arr);
}
