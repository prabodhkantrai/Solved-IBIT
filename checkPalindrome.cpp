#include <bits/stdc++.h>
using namespace std;

int solve(string A){
	int n=A.length();
	unordered_map<int,int> B;
	for(int i=0;i<n;i++){
		if(B.find(A[i])!=B.end()) B.erase(A[i]);
		else B.insert({A[i],A[i]});
	}
	if((n%2==1 && B.size()==1) || (n%2==0 && B.size()==0)) return 1;
	else return 0;
}
 
int main(){
	string A;
	getline(cin,A);
	cout<<solve(A);
	return 0;
}