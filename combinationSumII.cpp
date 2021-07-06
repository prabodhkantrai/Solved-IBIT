#include <bits/stdc++.h>
using namespace std;
set<vector<int>> myset;

void combination(vector<int> &A, int B, vector<int> &V, set<vector<int>> &myset, int s){
	if(B<0){
		return;
	}
	if(B==0){
		//G.push_back(V);
		myset.insert(V);
		return;
	}

	for(int i=s+1;i<A.size();i++){
		V.push_back(A[i]);
		combination(A, B-A[i], V, myset, i);
		V.pop_back();
	}

	return;
}

vector<vector<int>> combinationSum(vector<int> &A, int B){
	vector<vector<int>> G;
	vector<int>  V;
	sort(A.begin(), A.end());
	myset.clear();
	combination(A, B, V, myset, -1);

	for(vector<int> v : myset){
		G.push_back(v);
	}
	return G;
}
 
int main(){
	vector<int> C = {10,1,2,7,6,1,5};
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