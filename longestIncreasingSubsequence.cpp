#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A){
	int n= A.size();
	int lis[n];
	for(int i=0;i<n;i++){
		lis[i]=1;
	}
	int maxL = 1;

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(A[j]<A[i] && lis[j] + 1 > lis[i]){
				lis[i] += 1;
				if(lis[i]>maxL) maxL = lis[i];
			}
		}
	}

	return maxL;
}
 
int main(){

	vector<int> A = {50, 3, 10, 7, 40, 80};
	cout<<solve(A);

	return 0;
}