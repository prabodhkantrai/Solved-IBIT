#include <bits/stdc++.h>
using namespace std;
 
vector<int> kth(vector<int> &A, int k){
	/*vector<int> V;
	make_heap(A.begin(), A.end());
	while(k--){
		V.push_back(A.front());
		pop_heap(A.begin(), A.end());
		A.resize(A.size()-1);
	}
	return V;*/

	vector<int> V;
	priority_queue<int> D;
	for(int c:A){
		D.push(c);
	}

	while(k--){
		V.push_back(D.top());
		D.pop();
	}
	return V;
}

int main(){
	vector<int> A = {3,2,1,5,6,4};
	int k;
	cin>>k;
	vector<int> G = kth(A,k);
	for(int c:G)cout<<c;
	return 0;
}