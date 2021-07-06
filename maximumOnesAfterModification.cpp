#include <bits/stdc++.h>
using namespace std;

int solve (vector <int> &A, int B){
	int numzeros=0, numtot, maxlength = 0;
	/*for(int i=0;i<A.size();i++){
		numzeros = 0;
		numtot = 0;
		for(int j=i;j<A.size();j++){
			if(A[j]==0){
				numzeros +=1;
			}
			if(numzeros>B){
				break;
			}
			numtot+=1;
		}
		if(numtot>maxlength){
			maxlength = numtot;
		}
	}
	return maxlength;*/
	int N = A.size();
	int i=0;
	for(int j=0;j<N;j++){
		if(A[j]==0){
			numzeros+=1;
		}

		while(numzeros>B){
			if(A[i]==0){
				numzeros--;
			}
			i++;
		}

		if(j-i+1>maxlength){
			maxlength = j-i+1;
		}
	}
	return maxlength;
}
 
int main(){
	vector<int> A;
	int B,n,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		A.push_back(x);
	}
	cin>>B;
	cout<<solve(A,B);

	return 0;
}