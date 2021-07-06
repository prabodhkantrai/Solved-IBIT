#include <bits/stdc++.h>
using namespace std;
 
void gray(int A, vector<string> &V){
	if(A==1){
		return;
	}
	int n=V.size();

	for(int i=n-1;i>=0;i--){
		V.push_back(V[i]);
	}

	for(int i=0;i<V.size();i++){
		if(i<V.size()/2){
			string temp = "0" + V[i];
			V[i] = temp;
		}
		else{
			string temp = "1" + V[i];
			V[i] = temp;
		}
	}

	gray(A-1, V);
} 

vector<int> grayCode(int A){
	vector<string> V = {"0","1"};
	gray(A,V);
	vector<int> B;
	for(int i=0;i<V.size();i++){
		int temp = 0, x=0;
		for(int j=V[i].length()-1;j>=0;j--){
			temp+= (int)(V[i][j] - '0')*pow(2,x);
			x++;
		}
		B.push_back(temp);
	}
	return B;
}


/*# define ll long long 
void helper(int A, vector<int> &res, int size, int num){
    if(num == size) return; //base
    
    int pow = num/2;
    res.push_back(num^pow);
    helper(A, res, size, num+1);
}

vector<int> grayCode(int A) {
    vector<int> res;
    ll size = pow(2, A);
    helper(A, res, size, 0);
    return res;
    
}*/

int main(){
	int A;
	cin>>A;
	vector<int> G = grayCode(A);
	for(int i=0;i<G.size();i++){
		cout<<G[i]<<endl;;
	}

	return 0;
}