#include <bits/stdc++.h>
using namespace std;
	
int unqiuePaths(int A, int B){
	int path = 0;
	vector <int> x;
	for(int i=1; i<A;i++){
		x.push_back(0);
	}
	for(int i=1; i<B;i++){
		x.push_back(1);
	}
	while(next_permutation(x.begin(), x.end())){
		path+=1;
	}
	return path + 1;
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<unqiuePaths(a,b);
	return 0 ;
}