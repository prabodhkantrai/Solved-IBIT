#include <bits/stdc++.h>
using namespace std;
 
int solve(string A) {
    stack<char> B;

    int count=0;
    for(int i=0;i<A.length();i++){
        if(A[i]=='('){
            B.push(A[i]);
        }
        else if(B.empty()) return 0;
        else if(A[i]==')' && B.top() == '('){
            B.pop();
        }
        /*else if(A[i]=='}' && B.top() == '{'){
            B.pop();
        }
        else if(A[i]==']' && B.top() == '['){
            B.pop();
        }*/
        else
            return 0;
    }
    if(B.empty())
        return 1;
    return 0;
}


int main(){
    string A = "(()())";
    cout<<solve(A);
    return 0;
}