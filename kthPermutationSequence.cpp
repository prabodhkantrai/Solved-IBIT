#include <bits/stdc++.h>
using namespace std;

int k;
string temp;

void permV(int i, vector<int> &A, int B){
	if(i==A.size()-1){
		//G.push_back(A);
		k=k-1;
		if(k==0){
			for(int i=0;i<A.size();i++){
				temp = temp + to_string(A[i]);
			}
		}
		return;
	}
	for(int s=i;s<A.size();s++){
		swap(A[i],A[s]);
		permV(i+1, A, B);
		swap(A[i],A[s]);
	}
}

string getPermutation(int A, int B) {
	//vector<vector<int>> G;
	k = B;
	temp = "";
	vector<int> G;
	for(int i=1;i<=A;i++){
		G.push_back(i);
	}
	permV(0, G, B);
	return temp;

	/*vector<int> v;
	for(int i=1;i<=A;i++)v.push_back(i);

	do{
	    B--;
	}while(next_permutation(v.begin(),v.end()) && B!=1);

	string s="";
	for(int i: v){
	    s = s +  to_string(i); 
	}
	return s;*/
}

 
int main(){
	int A,B;
	string C;
	cin>>A;
	cin>>B;
	string G = getPermutation(A,B);
	cout<<G;
	return 0;
}