#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector <string> &A){
	stack<int> B;
	int eval = 0;

	for(int i=0;i<A.size();i++){
		if((A[i][0]>='0' && A[i][0]<='9') || ((A[i][0]=='-') && (A[i][1]>='0' && A[i][1]<='9'))){
			int num=0, j=0, fact = 1;
			if(A[i][0]=='-'){
				fact = -1;
				j=1;
			}
			for(;j<A[i].length();j++){
				num=num*10;
				num = num + (int)(A[i][j] - '0');
			}
			B.push(num*fact);
		}
		else if(A[i][0]=='+' && B.size()>=2){
			int c = B.top();
			B.pop();
			c+=B.top();
			B.pop();
			B.push(c);
		}
		else if(A[i][0]=='-' && B.size()>=2){
			int c = B.top();
			B.pop();
			c=B.top() - c;
			B.pop();
			B.push(c);
		}
		else if(A[i][0]=='*' && B.size()>=2){
			int c = B.top();
			B.pop();
			c=B.top()*c;
			B.pop();
			B.push(c);
		}
		else if(A[i][0]=='/' && B.size()>=2){
			int c = B.top();
			B.pop();
			c=B.top()/c;
			B.pop();
			B.push(c);
		}
		//cout<<B.top();
	}
	return B.top();



	/*int Solution::evalRPN(vector<string> &A) {
	stack<string>k;
	for(int i = 0; i < A.size(); i++)
    	if(A[i] == "/" || A[i] == "*" || A[i] == "+" || A[i] == "-") {
        int y = stoi(k.top());k.pop();
        int x = stoi(k.top());k.pop();
        switch(A[i][0]) {
            case '+':  k.push(to_string(x + y));break;
            case '-':  k.push(to_string(x - y));break;
            case '*':  k.push(to_string(x * y));break;
            case '/':  k.push(to_string(x / y));break;
        }
    }
    else k.push(A[i]);
    
	return stoi(k.top())*/
}

int main(){

	vector <string> A = {"-1"};
    cout<<evalRPN(A);

	return 0;
}