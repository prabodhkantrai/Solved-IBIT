#include <bits/stdc++.h>
using namespace std;

string mx = "";

void find(string A, int B){
	/*if(B==0){
		if(mx<A) mx = A;
		return;
	}
	for(int i=0;i<A.length();i++){
		for(int j=i+1;j<A.length();j++){
				swap(A[i], A[j]);
				find(A, B-1);
				swap(A[i], A[j]);
		}
	}*/
	if(B==0){
		return;
	}
	string max="";
	string currmax = 0;
	for(int i=0;i<A.length();i++){
		if(A[currmax]<A[i]){
			currmax = i;
			swap(A[i],A[0]);
			string alt = A;
			alt.erase(alt.begin());
			max = A[0] + solve(alt, --B);
			swap(A[i], A[0]);
			if(max>mx)mx = max;
		}
	}
}

string solve(string A, int B){
	mx = A;
	if(B==0){
		return A;
	}
	string max="";
	int currmax = 0;
	for(int i=0;i<A.length();i++){
		if(A[currmax]<A[i]){
			currmax = i;
			swap(A[i],A[0]);
			string alt = A;
			alt.erase(alt.begin());
			max = A[0] + solve(alt, --B);
			swap(A[i], A[0]);
			if(max>mx)mx = max;
		}
	}
	return mx;
}

 
int main(){
	string A;
	cin>>A;
	int B;
	cin>>B;
	cout<<solve(A,B);
	return 0;
}