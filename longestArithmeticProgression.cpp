#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A){
	 	int n = A.size();
        if(n<=2) return n;
        
        int maxSize = 2, diff;

        vector<unordered_map<int,int>> V (n);
        
        for(int i=1;i<A.size();i++){
            for(int j=0;j<i;j++){
                diff = A[i] - A[j];
                if(V[j].find(diff)!=V[j].end()){
                    V[i][diff] = V[j][diff] + 1;
                    maxSize = max(V[i][diff], maxSize);
                }
                else{
                    V[i][diff] = 2;
                }
            }    
        }
        
        return maxSize;
}
 
int main(){

	vector<int> A = {83,20,17,43,52,78,68,45};
	cout<<solve(A);

	return 0;
}