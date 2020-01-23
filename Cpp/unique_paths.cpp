/*
* Q. Count all the possible paths from top left to bottom right of a mXn matrix with the constraints that 
* from each cell you can either move only to right or down.
*/

// My Logic: any location grid[i,j] can be reached from top and left grid cell. Thus total no of paths is simply
addition of total number of paths to left grid and top grid.
#include <iostream>
#include <vector>
using namespace std;
void printGrid(vector<vector<int>> grid,int m, int n){
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}
int uniquePath(int m, int n) {
  // create grid matrix of m rows and n columns and initialize to 0
  vector<vector<int>> grid(m, vector<int>(n,0));
  grid[0][0] = 0;
  for(int i=1; i<m; i++)
    grid[i][0] = 1;
  for(int j=1; j<n; j++)
    grid[0][j] = 1;
  for(int i=1; i<m; i++){
    for(int j=1; j<n; j++) {
      grid[i][j] = grid[i-1][j] + grid[i][j-1];
    }
  }
  printGrid(grid,m,n);
  return grid[m-1][n-1];
}
int main() {
  int noOfWays = uniquePath(3,3);
  cout << noOfWays;
}
