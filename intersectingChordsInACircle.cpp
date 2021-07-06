#include <bits/stdc++.h>
using namespace std;
int M = 1e9 + 7;
int solve(int A){
	int n = 2*A;
	long long int count[n+1];
	count[0] = 1;
	count[2] = 1;
	for(int i=4;i<=n;i+=2){
		count[i]=0;
		for(int j=0;j<i-1;j+=2){
			count[i] = (count[i]%M + ((count[j]%M)*(count[i-j-2]%M))%M)%M;
		}
	}

	return count[n]%M;
}
 
int main(){

	cout<<solve(65);

	return 0;
}