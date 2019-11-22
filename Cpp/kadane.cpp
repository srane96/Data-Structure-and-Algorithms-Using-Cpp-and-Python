#include <iostream>
#include <vector>
// This has time complexity of O(n^3)
void getMaxSumBruteForceO3(std::vector<int> &arr) {
  int maxSum = 0;
  for(int i=0; i<arr.size(); i++) {
    for(int j=0; j<arr.size(); j++) {
      int sum = 0;
      for(int k=i; k <= j; k++) {
        sum += arr[k];
      }
      if(sum > maxSum)
        maxSum = sum;
    }
  }
  std::cout << "Brute Force max sum: " << maxSum << std::endl;
}

// This has time complexity of O(n^2)
void getMaxSumBruteForceO2(std::vector<int> &arr) {
  int maxSum = 0;
  for(int i=0; i<arr.size(); i++) {
    int sum = 0;
    for(int j=i; j<arr.size(); j++) {
      sum += arr[j];
      if(sum > maxSum)
        maxSum = sum;
    }
  }
  std::cout << "Brute Force max sum2: " << maxSum << std::endl;
}

// This has time complexity of O(n)
void KadaneAlgorithm(std::vector<int> &arr) {
  int maxSum = 0;
  int sum = 0;
  for(int i=0; i < arr.size(); i++) {
    sum = std::max(sum + arr[i], arr[i]);
    maxSum = std::max(maxSum, sum);
  }
  std::cout << "Kadane output: " << maxSum << std::endl;
}
int main() {
  std::vector<int> arr{-1,2,4,-3,5,2,-5,2};
  getMaxSumBruteForceO3(arr);
  getMaxSumBruteForceO2(arr);
  KadaneAlgorithm(arr);
  std::cout << "Hello World!\n";
}
