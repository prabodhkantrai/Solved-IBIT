#include <bits/stdc++.h>
using namespace std;

int maxSpecialProduct(vector<int> &A) {
	long long int maxsp = -1;
	stack<int> maxh;
	stack<int> minh;
	if(A.size()==0 || A.size()==1 ||A.size()==2) return 0;

	maxh.push(0);
	for(int i=A.size()-1;i>1;i--){
		minh.push(i);
	}
	int lv , rv;
	for(int i=1;i<A.size()-1;i++){
		while(!maxh.empty() && A[maxh.top()]<=A[i]){
			maxh.pop();
		}

		long long int sp=0;

		for(int k=i+1;k<A.size();k++){
			if(A[k]>A[i]){
				sp = k;
				break;
			}
		}

		/*while(!minh.empty() && A[minh.top()]<A[i]){
			minh.pop();
		}*/

		if(maxh.empty()){
			sp=0;
		}
		else sp *= maxh.top();

		/*if(minh.empty()){
			sp=0;
		}
		else sp *= minh.top();*/

		cout<<sp<<endl;

		if(sp>maxsp) maxsp =sp;

		maxh.push(i);
		//int k = minh.top();
		/*if(minh.empty()){
			for(int k=A.size()-1;k>i+1;i--){
				minh.push(i);
			}
		}
		else if(minh.top()==i+1){
			minh.pop();
		}
		else{
			while(minh.top()>i+2){
				minh.push(minh.top()-1);
			}
		}*/
	}

	return maxsp % 1000000007;
}	


 
int main(){
	vector<int> A = {4, 6, 5, 5, 6, 6, 5, 6, 7, 5, 5, 7, 7};
	cout<<maxSpecialProduct(A);

	return 0;
}