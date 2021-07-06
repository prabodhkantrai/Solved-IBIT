#include <bits/stdc++.h>
using namespace std;

int searchMatrix(vector<vector<int>> &A, int B){
	int mid, low = 0, high = A.size() - 1;
	int indy;
	while(low<=high){
		mid = low + (high-low)/2;
		if(A[mid][0] == B) return 1;
		else if(A[mid][0] > B){
			high=mid-1;
		}
		else if(A[mid][A[0].size()-1] <B){
			low = mid+1;
		}
		else{
			indy = mid;
			break;
		}
	}

	low = 0;
	high = A[0].size()-1;

	while(low<=high){
		mid = low + (high-low)/2;
		if(A[indy][mid] == B) return 1;
		else if (A[indy][mid] > B) high = mid-1;
		else if(A[indy][mid] <B) low = mid+1;
	}
	return 0;
}

int main(){
	int m, n, x, b;
	cin>>n;
	cin>>m;
	vector <vector<int>> A;
	for(int i=0;i<n;i++){
		vector<int> v;
		for(int j=0;j<m;j++){
			cin>>x;
			v.push_back(x);
		}
		A.push_back(v);
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}

	cin>>b;
	cout<<searchMatrix(A,b);


	return 0;
}