#include <iostream>
#include <vector>
using namespace std;
vector<int> merge(vector<int> left, vector<int> right) {
  vector<int> result;
  int i=0;
  int j=0;
  while(i < left.size() && j < right.size()) {
    if(left[i] < right[j]) {
      result.emplace_back(left[i]);
      i++;
    } else {
      result.emplace_back(right[j]);
      j++;
    }
  }
  while(i < left.size()) {
    result.emplace_back(left[i]);
    i++;
  }
  while(j < right.size()) {
    result.emplace_back(right[j]);
    j++;
  }
  return result;  
}

vector<int> mergeSort(vector<int> list) {
  cout << "called " << endl;
  vector<int> left;
  vector<int> right;
  int n= list.size();
  for(int i=0; i < n; i++) {
    if(i < n/2)
      left.emplace_back(list[i]);
    else
      right.emplace_back(list[i]);
  }
  if(left.size() > 1)
    left = mergeSort(left);
  if(right.size() > 1)
    right = mergeSort(right);  
  return merge(left,right);
}

int main() {
  vector<int> test = {9,8,7,6,5,4,3,2,2,1,1};
  vector<int> result = mergeSort(test);
  for(int i=0; i<result.size();i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;
}
