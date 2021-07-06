#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B){
	vector<int> arr (B+1, 0);
	arr[0] = 1;

	for(int i=0;i<A.size();i++){
		for(int j=A[i];j<=B;j++){
			arr[j] = (arr[j] + arr[j-A[i]])%1000007;
		}
	}

	return arr[B];
}
 
int main(){

	vector<int> A = {1,2,5};
	cout<<solve(A, 5);

	return 0;
}