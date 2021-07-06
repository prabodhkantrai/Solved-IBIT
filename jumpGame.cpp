#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A){
	int n = A.size();
	int jumps[n];

	for(int i=0;i<n;i++){
		jumps[i] = n-1;
	}

	jumps[0]=0;

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			//if(proof[i]==true) break;
			if(A[j] >= i-j && jumps[j] + 1 < jumps[i]){
				jumps[i] = jumps[j] + 1;
				cout<<jumps[i];
			}
		}
		cout<<endl;
	}

	return jumps[n-1];

	//FASTER SOLUTIO(N)
	/*int reach=0;
	for(int i=0;i<A.size();i++)
	{
	if(reach<i)
	return false;
	reach=max(reach,i+A[i]);
	}
	return true;
*/
}
 
int main(){

	vector<int> A = {2,3,0,1,4};
	cout<<solve(A);

	return 0;
}