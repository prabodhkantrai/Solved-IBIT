#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<char>>& A){
	 	int n = A.size();
        int m = A[0].size();
        int plus[n][m];
        int maxS = 0;

        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++) {
                 plus[i][j] = A[i][j] - '0';
            }
        }

        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i-1>=0 && j-1>=0) && A[i][j]!='0' && A[i-1][j]!='0' && A[i][j-1]!='0' && A[i-1][j-1]!='0'){
                   	plus[i][j] = min(plus[i-1][j-1], min(plus[i-1][j], plus[i][j-1])) + 1;                   	
                }
                maxS = max(plus[i][j], maxS);
            }
        }
        //cout<<maxS;
        return pow(maxS,2);
}
 
int main(){

	vector<vector<char>> A;
	for(int i=0;i<80;i++){
		A.push_back(vector<char>());
		for(int j=0;j<80;j++){
			A[i].push_back('1');
		}	
	}

	cout<<solve(A);

	/*char l= '79';
	l+=1;
	cout<<l+1;*/
	return 0;
}