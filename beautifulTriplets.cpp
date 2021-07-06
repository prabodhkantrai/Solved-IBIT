#include <bits/stdc++.h>
using namespace std;

int solve(int d, vector<int> arr){
	int p=0,q=0,r=0;
	int count=0;

	while(p<arr.size()-2 && q<arr.size()-1 && r<arr.size()){
		while(q<=p && q<arr.size()-1){
			q++;
		}

		//cout<<q;

		while(r<=q && r<arr.size()){
			r++;
		}
		//cout<<r;

		if(arr[q] - arr[p] == d && arr[r]-arr[q] == d){
			count++;
			p++;
			continue;
		}

		if(arr[q] - arr[p] < d){
			q++;
		}
		else if(arr[q] - arr[p] > d){
			p++;
		}
		else if(arr[r] - arr[q] > d){
			q++;
		}
		else if(arr[r] - arr[q] < d){
			r++;
		}

	}

	return count;
}
 
int main(){

	vector<int> A = {1,2,4,5,7,8,10};
	cout<<solve(3, A);

	return 0;
}