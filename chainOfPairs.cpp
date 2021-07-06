#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &A){
	int n = A.size();
	sort(A.begin(),A.end());
	vector<int> L (n,1);
	int maxC = INT_MIN;

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(A[j][1]<A[i][0] && L[i]<L[j]+1){
				L[i]=L[j] + 1;
			} 
		}
		if(L[i]>maxC) maxC = L[i];
	}
 
	return maxC;
}
 
int main(){

	vector<vector<int>> A =  {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};

	cout<<solve(A);



	return 0;
}