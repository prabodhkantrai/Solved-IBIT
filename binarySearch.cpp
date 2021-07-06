#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector <int> &A, int low, int high, int element ){
	int m = low + (high-low)/2;
	if(low>high) return -1;
	if(A[m] == element) return m;
    
	else if(A[m]>element){
		return binarySearch(A, low, m-1, element);
	}
	else if(A[m]<element){
		return binarySearch(A, m+1, high, element);
	}
}

int main(){

	int x,n, element;
	cin>>x;
	vector <int> A;
	for(int i=0;i<x;i++){
		cin>>n;
		A.push_back(n);
	}
	cin>>element;
	cout<<binarySearch(A, 0, n-1, element);

	return 0;
}