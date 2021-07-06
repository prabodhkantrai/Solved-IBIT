#include <bits/stdc++.h>
using namespace std;

bool cmp(const vector<int> &A, const vector<int> &B){
	return A[2]<B[2];
}

int solve(int A, vector<vector<int>> &B){
	sort(B.begin(), B.end(), cmp);
	int parent[n+1];
    for(int i=0; i<=n; i++) parent[i]=i;
    int count=0;
    int i=-1;int sum=0;
    while(count!=n-1){
        i++;
        vector<int> c=b[i];
        // return c[2];
        int k=c[0];
        int j=c[1];
        while(parent[k]!=k){
            k=parent[k];
        }
        while(parent[j]!=j){
            j=parent[j];
        }
        
        if(k!=j)
         {sum+=c[2];count++;parent[k]=j;}
        
    }
    return sum;
}
 
int main(){

	vector<vector<int>> B = {{1, 2, 1},{2, 3, 4},{1, 4, 3},{4, 3, 2},{1, 3, 10}}; 
	solve(4, B);

	return 0;
}