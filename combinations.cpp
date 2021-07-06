#include <bits/stdc++.h>
using namespace std;

void combination(int A, int B, vector<vector<int>> &G, vector<int> &V, int s){

	if(B==0){
		G.push_back(V);
		return;
	}

	for(int i=s;i<=A;i++){
		V.push_back(i);
		combination(A, B-1, G, V, i+1);
		V.pop_back();
	}
	return;
}
 
vector<vector<int>> combine(int A, int B){
	vector<int> V;
	vector<vector<int>> G;
	combination(A,B,G,V, 1);
	return G;
}

int main(){
	int A,B;
	cin>>A;
	cin>>B;
	vector<vector<int>> G = combine(A, B);
		for(int i=0;i<G.size();i++){
		for(int j=0;j<G[i].size();j++){
			cout<<G[i][j];
		}
		cout<<endl;
	}


	return 0;
}