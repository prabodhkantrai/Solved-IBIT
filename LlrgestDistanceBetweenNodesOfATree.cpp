#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int>adj[], int root, int &ans){
    if(adj[root].size()==0) return 1;
    int max1=0,max2=0;
    for(int i=0;i<adj[root].size();i++){
        int h=dfs(adj,adj[root][i],ans);
        if(h>max1){
            max2=max1;
            max1=h;
        }else if(h>max2){
            max2=h;
        }
    }
    ans=max(ans,max1+max2);
    
    return max(max1,max2)+1;
}


int solve(vector<int> &A){
	int n=A.size();
    vector<int>adj[n+1];
    int root;
    for(int i=0;i<A.size();i++){
        if(A[i]==-1){
            root=i;
            continue;
        }else{
         adj[A[i]].push_back(i);   
        }
    }
    int ans=0;
    if(adj[root].size()==0) return 0;
    dfs(adj,root,ans);
    return ans;
}


/*
int helper(vector<int> &A, vector<int> &V, unordered_map<int, list<int>> &mp, int i, int count){
	V[i] = 1;
	int temp = count;
	for(auto neg : mp[i]){
		if(V[neg] == 0)
			temp = max(temp, helper(A, V, mp, neg, count+1));
	}
	return temp;
}

int Solution::solve(vector<int> &A) {
vector<int> V (A.size(), 0);
    int n = A.size();
	if(n==1) return 0;
	unordered_map<int, list<int>> mp;

	for(int i=0;i<n;i++){
		if(A[i]!=-1){
			mp[i].push_back(A[i]);
			mp[A[i]].push_back(i);
		}
	}

	int maxC = INT_MIN;
	for(int i=0;i<n;i++){
		vector<int> V (n, 0);
		maxC = max(maxC, helper(A, V, mp, i, 0));
	}

	return maxC;
}

*/
 
int main(){
	vector<int> B = {-1,0,0,0,3};
	cout<<solve(B);
	return 0;
}