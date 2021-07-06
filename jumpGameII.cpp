#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A){
	/*int n = A.size();
	int jumps[n];

	for(int i=0;i<n;i++){
		jumps[i] = i;
	}

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(A[j] >= i-j && jumps[j] + 1 < jumps[i]){
				jumps[i] = jumps[j] + 1;
			}
		}
	}

	return jumps[n-1];*/

	int n = A.size();
    if(n==1 || n==0) return 0;
    if(A[0]==0) return -1;
	int steps = 0;                           
	int reach = A[0];
	int maxReach = A[0];
	int i=1;
	int index = 0;
	while(reach<n-1){
		while(i<=reach){
			if(A[i]+i>maxReach){
				maxReach = A[i] + i;
				index = i;
			}
			i++;
		}
		i=index;
		reach = maxReach;
		steps++;
	}
    if(reach>=n-1)
	    return steps+1;
	return -1;
}
 
int main(){

	vector<int> A = {0, 46, 46, 0, 2, 47, 1, 24, 45, 0, 0, 24, 18, 29, 27, 11, 0, 0, 40, 12, 4, 0, 0, 0, 49, 42, 13, 5, 12, 45, 10, 0, 29, 11, 22, 15, 17, 41, 34, 23, 11, 35, 0, 18, 47, 0, 38, 37, 3, 37, 0, 43, 50, 0, 25, 12, 0, 38, 28, 37, 5, 4, 12, 23, 31, 9, 26, 19, 11, 21, 0, 0, 40, 18, 44, 0, 0, 0, 0, 30, 26, 37, 0, 26, 39, 10, 1, 0, 0, 3, 50, 46, 1, 38, 38, 7, 6, 38, 27, 7, 25, 30, 0, 0, 36, 37, 6, 39, 40, 32, 41, 12, 3, 44, 44, 39, 2, 26, 40, 36, 35, 21, 14, 41, 48, 50, 21, 0, 0, 23, 49, 21, 11, 27, 40, 47, 49 };
	cout<<solve(A);

	return 0;
}