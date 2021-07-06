#include <bits/stdc++.h>
using namespace std;

set<string> myset;
bool isValid(string temp){
	stack<char> B;
	/*int count=0;
	for(int i=0;i<temp.length();i++){
		if(temp[i]=='(')count++;
		else count--;
	}
	if(count==0) return true;
	return false;*/
    for(int i=0;i<temp.length();i++){
        if(temp[i]=='('){
            B.push(temp[i]);
        }
        else if(B.empty()) return false;
        else if(temp[i]==')' && B.top() == '('){
            B.pop();
        }
        else
            return false;
    }
    if(B.empty())
        return true;
    return false;
}

void helper(int A, vector<string> &res, string s){
	if(s.length() == 2*A)
        {
            if(isValid(s))
            res.push_back(s);
            
            return;
        }
        
    helper(A, res, s + "(");
    helper(A, res, s + ")");  

	return;
}

vector<string> generateParenthesis(int A) {
	/*string temp = "";
	temp.clear();
	for(int i=0;i<A;i++){
		temp+='(';
	}
	for(int i=0;i<A;i++){
		temp+=')';
	}
	vector<string> G;
	helper(A, temp, 0);
	for(string c : myset){
		G.push_back(c);
	}
	return G;*/
	vector<string> res;
        
    helper(A, res, "");
        
    return res;
}

 
int main(){
	int A;
	cin>>A;
	vector<string> G = generateParenthesis(A);
	for(int i=0;i<G.size();i++){
		cout<<G[i]<<endl;
	}
	return 0;
}