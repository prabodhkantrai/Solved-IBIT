#include <bits/stdc++.h>
using namespace std;

vector<int> maxone(vector<int> &A, int B){
	int count=0,maxcount=-1;
	int s=-1,len=-1;
	int i=0,j=0;
	while(j<A.size()){
		if(A[j]==0)count++;

		if(count>B){
			if(j-i>len){
				len = j-i;
				s=i;
			}	

			while(count>B){
				if(A[i]==0)count--;
				i++;
			}
		}
		if(j==A.size()-1){
			if(j-i+1>len){
				len = j-i+1;
				s=i;
			}	
		}

		j++;
	}
	
	vector<int> G;
	for(int i=s;i<s + len;i++){
		G.push_back(i);
	}

	return G;
}

int main(){
	vector<int> A = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1};
	int B = 33;
	vector<int> g  = maxone(A,B);
	for(int c : g) cout<<c;

	return 0;
}