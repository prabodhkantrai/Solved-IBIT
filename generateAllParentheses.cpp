#include <bits/stdc++.h>
using namespace std;
 
int isValid(string A) {
    stack<char> B;
    /*for(int i=0;i<A.length()/2;i++){
        if(A[i]=='(')
            B.push(')');
        else if(A[i]=='{')
            B.push('}');
        else if(A[i]=='[')
            B.push(']');
    }

    for(int i=A.length()/2;i<A.length();i++){
        if(B.top()!=A[i]){
            return 0;
        }
        B.pop();
    }
    return 1;*/

    int count=0;
    for(int i=0;i<A.length();i++){
        if(A[i]=='{' || A[i]=='(' || A[i]=='['){
            B.push(A[i]);
        }
        else if(B.empty()) return 0;
        else if(A[i]==')' && B.top() == '('){
            B.pop();
        }
        else if(A[i]=='}' && B.top() == '{'){
            B.pop();
        }
        else if(A[i]==']' && B.top() == '['){
            B.pop();
        }
        else
            return 0;
    }
    if(B.empty())
        return 1;
    return 0;
}


int main(){
    string A = " (((([{()}[]]{{{[]}}}))))";
    cout<<isValid(A);
    return 0;
}