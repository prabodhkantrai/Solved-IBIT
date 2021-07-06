#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &A){
	vector<vector<int>> G = A;
	int count;
	for(int i=0;i<G[0].size();i++){
		count=1;
		for(int j=0;j<G.size();j++){
			if(G[j][i]==0) count = 1;
			else{
				G[j][i] = count;
				count++;
			}
		}
	}

	for(int i=0;i<G.size();i++){
		sort(G[i].begin(), G[i].end(), greater<int>());
	}

	int area, maxArea = 0;
	for(int i=0;i<G.size();i++){
		for(int j=0;j<G[0].size();j++){
			area = G[i][j]*(j+1);
			if(area>maxArea) maxArea = area;
		}
	}

	return maxArea;
}
 
int main(){
	vector<vector<int>> A;
	int r,c;
	cin>>r>>c;
	int x;

	for(int i=0;i<r;i++){
		A.push_back(vector<int>());
		for(int j=0;j<c;j++){
			cin>>x;
			A[i].push_back(x);
		}
	}

	cout<<solve(A);


	return 0;
}