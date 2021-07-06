#include <bits/stdc++.h>
using namespace std;

string solve(string A){
	string B ;
	int arr[26] = {0};
	queue<char>C;
	for(int i=0;i<A.length();i++){
		C.push(A[i]);
		arr[(int)(A[i]-'a')] += 1;
		while(arr[(int)(C.front() - 'a')] > 1 && !C.empty()){
			C.pop();
		}
		if(C.empty()){
			B.push_back('#');
		}
		else B.push_back(C.front());
	}
	return B;
}
 
int main(){
	string A = "abadbc";
	cout<<solve(A);
	return 0;
}