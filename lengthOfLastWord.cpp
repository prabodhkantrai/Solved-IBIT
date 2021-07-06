#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(const string A){
	//vector <string> tokens;
	/*stringstream check(A);
	string intermediate;
	while(getline(check, intermediate, ' ')){

	}
	return intermediate.length();*/
	int count=0;
	for(int i=0;i<A.length();i++){
		if(A[i]!=' '){
			count++;
		}
		else if(A[i] == ' ' && i!=A.length()-1 && A[i+1]!=' '){
			count=0;
		}
	}
	return count;
}
 
int main(){
	string A;
	getline(cin, A);
	cout<<A.length();
	cout<<lengthOfLastWord(A);

	return 0;
}