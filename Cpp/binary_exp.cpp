#include <iostream>
using namespace std;
// recursive
long long  pow(long a, long b) {
  if(a == 0)
    return 0;
  if(b == 0)
    return 1;
  // a^n = [a^n/2]^2 if n == even
  // a^n = [a^n/2]^2 * a if n == odd
  long long ans = pow(a, b/2);
  if(b % 2 == 0)
    ans = ans * ans;
  else
    ans = ans * ans * a;
  return ans;  
}

// iterative
long long pow_itr(long a, long b) {
  long long res = 1;
  // naive = a * a and b-- while b > 0
  while(b > 0) {
    // if b is odd
    if(b & 1)
      res = res * a;
    // halve the power
    b = b >> 1;
    a = a * a;
  }
  return res;
}

// same logic can be applied to compute large exponents mod a number
// and the reason is that mod doesn't interfere with the multiplcations
// so (a.b)mod m = ( a mod m . b mod m ) mod m
long long pow_mod(long a, long b, int m) {
  a = a % m;
  long long res = 1;
  while (b > 0) {
    if(b & 1)
      a = res * a % m;
    b = b >> 1;
    a  = a * a % m;
  }
  return res; 
}

int main() {
  long a = 40;
  long b = 2;
  long long c = pow_itr(a,b);
  cout << c << endl;

  int d = 9;
  int e = d >> 1;
  cout << e;
}
