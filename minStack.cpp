#include <bits/stdc++.h>
using namespace std;
stack<int> ms;
stack<int> mst;


MinStack::MinStack() {
	while(!ms.empty()){
		ms.pop();
	}
	while(!mst.empty()){
		mst.pop();
	}
}

void MinStack::push(int x) {
   	ms.push(x);
   	vector<int> V;
   	if(mst.empty())mst.push(x);
   	else{
   		while(mst.top()<x){
   			V.push_back(mst.top())
   			mst.pop();
   		}
   		mst.push(x);
   		for(int i=V.size()-1;i>=0;i--){
   			mst.push(V[i]);
   		}
   	}
}

void MinStack::pop() {
    if(ms.empty()) return;
    vector<int> V;
    while(mst.top()!=ms.top()){
    	V.push_back(mst.top());
    	mst.pop();
    }
    mst.pop();
    for(int i=V.size()-1;i>=0;i--){
    	mst.push(V[i]);
    }
    ms.pop();
}

int MinStack::top() {
    return ms.top();
}

int MinStack::getMin() {
    return mst.top();
}

 
int main(){
	

	return 0;
}