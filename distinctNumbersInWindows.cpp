#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, int B){
	map<int, int> mp;
	vector<int> G;

	int i =0;
	while(i<B){
		mp[A[i]] = i;
		i++;
	}

	G.push_back(mp.size());

	while(i<A.size()){
		if(i-B == mp[A[i-B]])
			mp.erase(A[i-B]);

		

		mp[A[i]] = i;

		G.push_back(mp.size());
		i++;

	}

	return G;

}
 
int main(){
	vector<int> A  ={1,1,2,2};
	int B = 1;
	vector<int> G = solve(A,B);
	for(int c : G){
		cout<<c;
	}

	return 0;
}