#include <bits/stdc++.h>
using namespace std;

int solve(string s){
	string t = s;
	int n = s.length();
	int dp[n+1][n+1];

	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==0||j==0){
				dp[i][j]=0;
			}

			else if(s[i-1]==t[j-1] && i!=j){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	/*for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	if(dp[n][n]<=1) return 0;
	return 1;
}
 
int main(){
	cout<<solve("ABBA");


	return 0;
}