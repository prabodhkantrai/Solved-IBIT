#include <bits/stdc++.h>
using namespace std;

int X[8] = {1,1,0,-1,-1,-1,0,1};
int Y[8] = {0,1,1,1,0,-1,-1,-1};

int helper(vector<vector<int>> &A, vector<vector<int>> &rect, int y, int x, int m, int n){
	if(rect[y][x] == 1 || A[y][x] == 0) return 0;

	int sum = 0;

	rect[y][x] = 1;

	for(int i=0;i<8;i++){
		int a = x + X[i];
		int b = y + Y[i];

		if(a<n && a>=0 && b<m && b>=0)
				sum+=helper(A, rect, b, a, m, n);
	}

	return sum+1;
}

int solve(vector<vector<int>> &A){\
	int m = A.size();
	int n = A[0].size();
	vector<vector<int>> rect (m, vector<int>(n,0));
	//memset(rect, 0, sizeof(rect));
	int maxC = -1, newC;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			newC = helper(A, rect, i, j, m ,n);
			if(newC>maxC) maxC = newC;
		}
	}

	return maxC;
}
 
int main(){

	vector<vector<int>> A  = {{0,0,1,1,0},{1,0,1,1,0},{0,0,0,0,0},{0,0,0,0,1}};
	cout<<solve(A);

	return 0;
}