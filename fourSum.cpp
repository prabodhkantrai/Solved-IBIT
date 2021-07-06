#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &A, int B, vector<vector<int>> &G, vector<int> &V, int s){
	if(B==0 && V.size()==4){
		G.push_back(V);
		return;
	}
	for(int i=s;i<A.size();i++){
		V.push_back(A[i]);
		helper(A, B - A[i], G, V, i+1);
		V.pop_back();
	}
	return;

}

vector<vector<int>> fourSum(vector<int> &A, int B){
	/*vector<int> V;
	sort(A.begin(), A.end());
	vector<vector<int>> G;
	helper(A, B, G, V, 0);
	return G;*/
	sort(A.begin(), A.end());
	unordered_map<int, vector<int>> mymap;
	vector<int> V;
	vector<vector<int>> G;
	for(int i=0;i<A.size-3;i++){
		for(int j=i+1; j<A.size()-2;j++)
	}
	return G;
}
 
int main(){
	vector<int> A = {1,0,-1,0,-2,2};
	int B;
	cin>>B;
	vector<vector<int>> G = fourSum(A,B);
	for(int i=0;i<G.size();i++){
		for(int j=0;j<G[i].size();j++){
			cout<<G[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}