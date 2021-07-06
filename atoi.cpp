#include <bits/stdc++.h>
using namespace std;

int atoi(const string A){
	long long int num = 0, sign=1;
	int flag = 0;

	for(int i=0;i<A.length();i++){
		if(A[i]>='0' && A[i]<='9'){
			flag=1;
			num = num*10;
			num = num + A[i] - '0';
		}
		else if((A[i]=='-' || A[i] == '+') && (A[i+1]>='0' && A[i+1]<='9') && flag==0){
			if(A[i]=='-') sign = -1;
			if(A[i]=='+') sign = +1;
		}
		else if ((A[i]=='-' || A[i] == '+') && (A[i+1]<'0' || A[i+1]>'9') && flag==0){
			return 0;
		}
		else if(((A[i]<'0' || A[i]>'9') && A[i]!=' ') || (A[i]==' ' && (A[i-1]>='0' || A[i-1]<='9'))){
			break;
		}
		if(num>2147483647){
			if(sign==-1) return INT_MIN;
			else return INT_MAX;
		}
	}
	return sign*num;
}

 
int main(){

	string A;
	getline(cin, A);
	cout<<atoi(A);

	return 0;
}