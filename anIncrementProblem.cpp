#include <bits/stdc++.h>
using namespace std;


vector<int> solve(vector<int> &A) {
	unordered_map<int, int> map;
	unordered_map<int,int> iter;
	for(int i=0;i<A.size();i++){
		for(int j = 0; j<i ;j++){
			if(map[j] == A[i]){
				map[j] = map[j]  + 1;
				break;
			}
		}
		map[i] = A[i];
	}

	vector<int> V;

	for(int i=0;i<A.size();i++){
		V.push_back(map[i]);
	}

	return V;
}

 
int main(){
	vector<int> A  = {1,1};

	vector<int> G = solve(A);

	for(int i=0;i<G.size();i++){
		cout<<G[i];
	}
	return 0;
}