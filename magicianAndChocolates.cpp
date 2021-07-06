#include <bits/stdc++.h>
using namespace std;
 
int kth(int A, vector<int> &B){
	/*vector<int> V;
	make_heap(A.begin(), A.end());
	while(k--){
		V.push_back(A.front());
		pop_heap(A.begin(), A.end());
		A.resize(A.size()-1);
	}
	return V;*/

	long long int mx = 0;
	priority_queue<int> D;
	for(int c:B){
		D.push(c);
	}
	long long int c;
	while(A--){
		c = D.top();
		mx+=c;
		
		D.pop();
		D.push(floor(c/2));
	}
	return mx % 1000000007;
}

int main(){
	vector<int> A = {2, 4, 6, 8, 10};
	int k;
	cin>>k;
	int G = kth(k,A);
	cout<<G;
	return 0;
}