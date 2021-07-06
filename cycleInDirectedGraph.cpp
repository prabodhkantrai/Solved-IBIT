#include <bits/stdc++.h>
using namespace std;

#define UNPROCESSED 0
#define PROCESSING 1
#define PROCESSED 2


bool helper(vector<vector<int>> &adj, vector<int> &V, int root){
	if(V[root] == PROCESSING){
		return true;
	}

	V[root] = PROCESSING;

	for(auto neg : adj[root]){
		if(helper(adj, V, neg)){
			return true;
		}
	}

	V[root] = PROCESSED;

	return false;
}

int solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj (A+1);
	for(int i=0;i<B.size();i++){
		adj[B[i][0]].push_back(B[i][1]);
	}

	vector<int> V(A+1, UNPROCESSED);
	for(int i=1;i<=A;i++){
		if(helper(adj, V, i)){
			return true;
		}
	}

	return false;
}

 
int main(){
	vector<vector<int>> B = {{1,2},{2,3},{3,4},{4,5}};
	cout<<solve(5,B);

	return 0;
}