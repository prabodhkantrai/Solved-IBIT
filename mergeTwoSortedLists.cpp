#include <bits/stdc++.h>
using namespace std;

void merge(vector <int> &A, vector <int> &B){
	/*for(int i=0;i<A.size();i++){
		
		if(j==B.size()) break;
		if(B[j]<A[i]){
			A.insert(A.begin() + i, B[j]);
			j++;
			i--;
		}
		
	}
	for(int i=j;i<B.size();i++){
		A.push_back(B[i]);
	}*/

	vector<int> V;

	int i=0;
	int j=0;

	while(i<A.size() && j<B.size()){
		if(A[i]<B[j]){
			V.push_back(A[i]);
			i++;
		}
		else{
			V.push_back(B[j]);
			j++;
		}
	}

	if(i!=A.size()){
		while(i<A.size()){
			V.push_back(A[i]);
			i++;
		}
	}
	else if(j!=B.size()){
		while(j<B.size()){
			V.push_back(B[j]);
			j++;
		}
	}

	A=V;
}


 
int main(){
	int n1, n2,x ;
	cin>>n1;
	cin>>n2;
	vector <int> A, B;
	for(int i=0;i<n1;i++){
		cin>>x;
		A.push_back(x);
	}

	for(int i=0;i<n2;i++){
		cin>>x;
		B.push_back(x);
	}

	merge(A,B);

	for(int i=0;i<A.size();i++){
		cout<<A[i];
	}
	return 0;
}