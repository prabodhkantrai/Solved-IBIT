#include <bits/stdc++.h>
using namespace std;

int helper(const vector<int> &A, int x, bool flag){
	/*int mn = -1;
	for(int i=x+1;i<A.size();i++){
		if(A[i]<A[x]){
			mn = A[i];
			break;
		}
	}
	int mx = -1;
	if(!flag)
		for(int i=x+1;i<A.size();i++){
			if(A[i]>A[x]){
				mx = i;
				break;
			}
		}

	if(mn == -1 && flag){
		if(V.size()>maxL) maxL = V.size();
	}

	V.push_back(A[x]);

	if(mn != -1){
		helper(A,mn,true,V);
	}

	if(mx!=-1){
		helper(A,mx,false,V);
		helper(A,mx,true,V);
	}*/

	/*if(x<0) return 1;
	int mx = -1;
	if(!flag)
	for(int i = x-1;i>=0;i--){
		if(A[i]>A[x]){
			mx = max(mx, 1 + helper(A,i,false));
		}
	}
	int mn = -1;
		for(int i = x-1;i>=0;i--){
			if(A[i]<A[x]){
				mn = max(mn, 1 + helper(A,i,true));
			}
		}

	return max(mx,mn);*/




}

int solve(const vector<int> &A){
	//return helper(A, A.size(), false);

	int n = A.size();

	vector<int> inc (n,1);
	vector<int> dec (n,1);

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(A[i]>A[j] && inc[i] < inc[j] + 1) inc[i]+=1;
		}
	}

	for(int i=n-2;i>=0;i--){
		for(int j=i+1;j<A.size();j++){
			if(A[i]>A[j] && dec[i] < dec[j] + 1) dec[i]+=1;
		}
	}


	int mx = 0;

	for(int i=0;i<n;i++){
		mx = max(mx, inc[i] + dec[i]);
	}


	return mx;
}
 
int main(){
	vector<int> A  = {12, 11, 40, 5, 3, 1};
	cout<<solve(A);

	return 0;
}