//  create heap from given array
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void print_vect(vector<int> arr) {
  for(int i=0; i< arr.size(); i++) 
    cout << arr[i] << " ";
  cout << endl;
}
// str = "max" if we want max-heap
// str = "min" if we want min-heap
vector<int> heapify(vector<int> arr, string str) {
  vector<int> heap;
  for(int i=0; i<arr.size(); i++) {
    heap.push_back(arr[i]);
    int current_ind = i;
    int parent_ind = (current_ind-1) / 2;
    if(str == "max"){
      while(parent_ind >=0 && heap[parent_ind] < heap[current_ind]) {
        int temp = heap[current_ind];
        heap[current_ind] = heap[parent_ind];
        heap[parent_ind] = temp;
        current_ind = parent_ind;
        parent_ind = (current_ind-1) / 2;
      }
    }
    else {
      while(parent_ind >=0 && heap[parent_ind] > heap[current_ind]) {
        int temp = heap[current_ind];
        heap[current_ind] = heap[parent_ind];
        heap[parent_ind] = temp;
        current_ind = parent_ind;
        parent_ind = (current_ind-1) / 2;
      }
    }
  }
  return heap;
}
int main() {
  vector<int> inp = {4, 10, 3, 5, 1};
  print_vect(inp);
  vector<int> ans = heapify(inp,"min");
  print_vect(ans);

  inp = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
  print_vect(inp);
  ans = heapify(inp,"max");
  print_vect(ans);
}
