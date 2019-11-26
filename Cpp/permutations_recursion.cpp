#include <iostream>
#include <vector>
// print the permutations
void printPerm(std::vector<int> arr) {
  for(int a:arr)
    std::cout << a << " ";
  std::cout << std::endl;  
}

// calculate permutation of all elements of a sequence recursively
void displayPermutations(std::vector<int> arr, std::vector<int> perm, std::vector<bool> visited) {
    if(perm.size() == arr.size()) {
      printPerm(perm);
    }
    for(int i=0; i<arr.size(); i++) {
      if(visited[i])
        continue;
      else {
        perm.push_back(arr[i]);
        visited[i] = true;
        displayPermutations(arr, perm,visited);
        visited[i] = false;
        perm.pop_back();
      }
    }
}
int main() {
  std::vector<int> arr{1,2,3,4};
  std::vector<int> perm;
  std::vector<bool> visited(arr.size(),false);
  displayPermutations(arr,perm,visited);
}
