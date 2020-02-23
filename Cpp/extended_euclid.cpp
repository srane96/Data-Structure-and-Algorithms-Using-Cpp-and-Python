#include <iostream>
#include <vector>
using namespace std;
int extended_euclid(int a, int b, int&x, int&y) {
  if(b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    int x1, y1;
    int g = extended_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return g; 
  }
}
int main() {
  std::cout << "Hello World!\n";
  int x, y;
  int g = extended_euclid(10,6,x,y);
  cout << y << " " << x;
}
