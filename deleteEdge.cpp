#include <bits/stdc++.h>
using namespace std;

int mx;
#define mod 1000000007

int helper(vector<int> &A, vector<vector<int>> &adj, vector<int> &vis, int netSum, int root){
	if(vis[root] == 1) return 0;

	int sum1 = A[root-1];
	int sum2 = 0;

	vis[root] = 1;

	for(auto neg : adj[root]){
		sum2 += helper(A,adj,vis,netSum,neg);
	}

	mx = max(mx, ((netSum - sum1 - sum2)%mod)*((sum1 + sum2)%mod)%mod);

	return sum1+sum2;
}

int solve(vector<int> &A, vector<vector<int>> &B){
	mx = 0;
	int n = A.size();
	int m = B.size();
	vector<int> vis(n+1, 0);
	vector<vector<int>> adj (n+1);

	for(int i=0;i<m;i++){
		adj[B[i][0]].push_back(B[i][1]);
		adj[B[i][1]].push_back(B[i][0]);
	}

	int netSum=0;
	for(int c : A) netSum+=c;

	cout<<netSum<<endl;

	helper(A, adj, vis, netSum, 1);

	return mx;
}
 
int main(){

	vector<int> A = {11, 12};
	vector<vector<int>> B = {{1,2}};

	cout<<solve(A,B);

	return 0;
}