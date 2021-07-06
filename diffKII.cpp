#include <bits/stdc++.h>
using namespace std;

int diffPossible(const vector<int> &A, int B){
	unordered_map<int,int> mymap;
	for(int i=0;i<A.size();i++){
		for(int j=i+1;j<A.size();j++){
			mymap.insert({abs(A[i]-A[j]), i});
		}
	}
	if(mymap.find(B)==mymap.end()){
		return 0;
	}
	return 1;
}
 
int main(){
	vector<int> A = {1,5,3};
	int K;
	cin>>K;
	cout<<diffPossible(A,K);


	return 0;
}