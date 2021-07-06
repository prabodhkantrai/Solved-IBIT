#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int * arr, int start, int end){
	for(int i=0;i<=end;i++){
		bool done = false;
		for(int j=0;j<=end-i;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				done=true;
			}
		}
		if(!done)
			break;
	}
}

int main(){

	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	bubbleSort(arr, 0, n-1);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}