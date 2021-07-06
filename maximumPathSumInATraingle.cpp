#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &A){
	for(int i=A.size()-2;i>=0;i--){
		for(int j=0;j<A[i].size();j++){
			A[i][j] += max(A[i+1][j], A[i+1][j+1]);
		}
	}

	return A[0][0];
}
 
int main(){

	vector<vector<int>> A = {{3},{7,4},{2,4,6},{8,5,9,3}};
	cout<<solve(A);

	return 0;
}