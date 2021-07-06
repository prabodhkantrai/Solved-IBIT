#include <bits/stdc++.h>
using namespace std;
int solve(string word1, string word2){
    int m = word1.length();
	int n = word2.length();
	int V[m+1][n+1];

	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0) V[i][j] = j;
			else if(j==0) V[i][j] = i;

			else if(word1[i-1] == word2[j-1]){
				V[i][j] = V[i-1][j-1];
			}
			else{
				V[i][j] = 1 + min(min(V[i][j-1], V[i-1][j]), V[i-1][j-1]);
			}


		}
	}
	return V[m][n];
}
 
int main(){



	return 0;
}