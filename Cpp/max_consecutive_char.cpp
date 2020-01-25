/**
* Q. find the longest consecutive character from the
*    given string.
**/
/**
* My logic: Create an array of occurance count. Start from left most  *     element. If current char is same as previous one then just
*     add 1 to the occurance count of previous one. if it is 
*     different than start again from one.
*     return max of the occurance count array.
*/
#include <iostream>
#include <string>
using namespace std;
void max_consecutive_char(string s) {
  int a[s.length()];
  a[0] = 1;
  for(int i=1; i<s.length(); i++) {
    if(s[i] == s[i-1]) 
      a[i] = a[i-1] + 1;
    else
      a[i] = 1;
  }
  int max_count=a[0];
  int max_index = 0;
  for(int i=1; i<s.length();i++) {
    if(a[i] > max_count){
      max_count = a[i];
      max_index = i;
    }
  }
  cout << "Max Count: " << max_count;
  cout << " and char is " << s[max_index];
}
int main() {
  max_consecutive_char("HHellssssso");
}
