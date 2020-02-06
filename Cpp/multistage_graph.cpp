/**
* Given a Multistage graph. Find the shortest path 
* from starting (0th) node to end (nth) node
**/
#include <iostream>
#include <vector>
#define INF 0
using namespace std;
void shortest_path(vector<vector<int>> G, int N) {
  /*
    List to define shortest distance from each node
    to the goal node
  */
  vector<int> costs(N);
  /*
    List to define what is the next shortest path node
    to go from current node
  */
  vector<int> next_index(N);
  // distance from goal to goal is zero
  costs[N-1] = 0;
  next_index[N-1] = -1;
  for(int i=N-2; i>=0; i--) {
    int min_cost = 99999;
    int next_ind = i;
    for(int k=i+1; k<N; k++) {
      if(G[i][k] !=0) {
        int cost = G[i][k] + costs[k];
        if(cost < min_cost) {
          min_cost = cost;
          next_ind = k;
        }
      }
    }
    costs[i] = min_cost;
    next_index[i] = next_ind;
  }
  int i = 0;
  cout << "Shortest path: ";
  while(i != -1) {
    cout << i << " "; 
    i = next_index[i];
  }
  cout << "\nPath cost: " << costs[0] << endl;
}

int main() {
  vector<vector<int>> G{
       {INF, 1, 2, 5, INF, INF, INF, INF}, 
       {INF, INF, INF, INF, 4, 11, INF, INF}, 
       {INF, INF, INF, INF, 9, 5, 16, INF}, 
       {INF, INF, INF, INF, INF, INF, 2, INF}, 
       {INF, INF, INF, INF, INF, INF, INF, 18}, 
       {INF, INF, INF, INF, INF, INF, INF, 13}, 
       {INF, INF, INF, INF, INF, INF, INF, 2}
      };
  shortest_path(G, 8);
}
