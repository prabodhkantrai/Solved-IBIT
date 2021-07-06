#include <bits/stdc++.h>
using namespace std;

void combination(vector<int> &A, int B, vector<int> &V, vector<vector<int>> &G, int s){
	if(B<0){
		return;
	}
	if(B==0){
		G.push_back(V);
		return;
	}

	for(int i=s;i<A.size();i++){
		V.push_back(A[i]);
		combination(A, B-A[i], V, G, i);
		V.pop_back();
	}

	return;
}

vector<vector<int>> combinationSum(vector<int> &A, int B){
	vector<vector<int>> G;
	vector<int>  V;
	sort(A.begin(), A.end());
	vector<int>::iterator ip;
	ip = std::unique(A.begin(), A.end());
	A.resize(std::distance(A.begin(), ip));
	combination(A, B, V, G, 0);
	return G;
}
 
int main(){
	vector<int> C = {8, 10, 6, 11, 1, 16, 8};
	int B;
	cin>>B;
	vector<vector<int>> G = combinationSum(C,B);
	for(int i=0;i<G.size();i++){
		for(int j=0;j<G[i].size();j++){
			cout<<G[i][j];
		}
		cout<<endl;
	}

	return 0;
}