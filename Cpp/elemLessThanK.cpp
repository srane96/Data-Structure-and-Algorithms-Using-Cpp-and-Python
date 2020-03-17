#include <iostream>
#include <vector>
#include <string>
using namespace std;
int count_no_less(vector<int>& arr, int k) {
  int l = 0;
  int h = arr.size()-1;
  int count = 0;
  while(l <= h) {
    int mid = (l + h) /2;
    if(arr[mid] <= k) {
      count += (mid - l)+1;
      l = mid + 1;
    }else {
      h = mid - 1;
    }
  }
  return count;
}
int main() {
  vector<int> arr{2,3,4,5,6,7,8,9};
  int ans = count_no_less(arr, 5);
  cout << ans;
}
