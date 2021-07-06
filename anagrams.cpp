#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int> > anagrams(const vector<string> &A) {
	vector<vector<int>> G;
	vector<int> V;
	unordered_map<float, int> map;
	int index = 0;
	for(int i=0;i<A.size();i++){
		float mul = 1;
		float sum = 0;
		for(char c : A[i]){
			mul += (c - 'a' + 1)*(c - 'a' + 1);
		}
		float key=mul;
		if(map.find(key)!=map.end()){
			G[map[key]].push_back(i+1);
		}
		else{
			map[key] = index;
			index++;
			vector<int> v = {i+1};
			G.push_back(v);
		}
	}
	return G;
}


int main(){
	string x;
	int n;
	cin>>n;
	vector<string> A = {"caat", "taac", "dog", "god", "acta"};
	vector<vector<int>> G = anagrams(A);
	for(int i=0;i<G.size();i++){
		for(int j=0;j<G[i].size();j++){
			cout<<G[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}