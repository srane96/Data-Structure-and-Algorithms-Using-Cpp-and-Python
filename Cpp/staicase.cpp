/**
There are n stairs, a person standing at the bottom wants to reach the top. 
person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top.
**/
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;
ll mod =1000000007;
int main() {
	//code
	int T;
	cin >> T;
	while(T>0){
	    long N;
	    cin >> N;
	    vector<long> L(N);
	    L[0] = 1;
	    L[1] = 2;
	    for(int i=2; i<N; i++)
	        L[i] = (L[i-1] + L[i-2])%mod;
	    cout << L[N-1] << endl;
	    T--;
	}
	return 0;
}
