#include <bits/stdc++.h>
using namespace std;

int column(string A){
	int x, col = 0;
	for(int i=0;i<A.length();i++){
		int y=26;
		col = col + ((int)A[i] - 64)*(pow(26,(A.length()-1-i)) + 0.1);
	}
	return col;
}

int main(){
	string x;
	cin>>x;
	cout<<column(x);
	return 0;
}