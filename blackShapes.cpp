#include <bits/stdc++.h>
using namespace std;

int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};


void helper(vector<vector<char>> &A, vector<vector<int>> &V, int i, int j, int m, int n){

	if(A[i][j]=='O') return;

	V[i][j] = 1;

	for(int k=0;k<4;k++){
		int x = i+X[k];
		int y = j+Y[k];
		if(x<m && x>=0 && y<n && y>=0 && V[x][y] == 0)
			helper(A, V, x, y, m, n);
	}

	return;
}

int solve(vector<vector<char>> &A){
	int m = A.size();
	int n = A[0].size();
	vector<vector<int>> V (m, vector<int> (n,0));
	int count=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(A[i][j]=='X' && V[i][j] == 0){
				helper(A, V, i, j, m, n);
				count++;
			}
		}
	}
	return count;
}
 
int main(){

	vector<vector<char>> A = {{'O','O','O','X','O','O','O'}
          ,{'O','O','X','X','O','X','O'}
          ,{'O','X','O','O','O','X','O'}};
    cout<<solve(A);

	return 0;
}