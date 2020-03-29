#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// Implement Moor's voting algorithm
int getMajorityElem(vector<int> arr) {
  int maj = 0;
  int count = 1;
  for(int i=1; i < arr.size(); i++) {
    if(arr[maj] == arr[i])
      count++;
    else
      count--;
    if(count ==0) {
      maj = i;
      count = 1;
    }
  }
  return arr[maj];
}

int main() {
  vector<int> arr{2,2,2,2,5,7,8};
  int a = getMajorityElem( arr );
  // check if a occurs more than n/2 times in the array
  int count =  0;
  for(int i=0; i<arr.size(); i++) {
    if(arr[i] == a)
      count++;
  }
  if(count > arr.size()/2)
    cout << a << " is majority element" ;
  else
    cout << "Majority elem NOT present" ; 
}
