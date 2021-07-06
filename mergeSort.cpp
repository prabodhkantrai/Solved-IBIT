#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int start, int mid, int end){
	int temp[end-start+1];
	int i=start;
	int j=mid+1;
	int k=0;

	while(i<=mid && j<=end){
		if(arr[i]<=arr[j]){
			temp[k] = arr[i];
			k+=1;
			i+=1;
		}
		else{
			temp[k] = arr[j];
			k+=1;
			j+=1;
		}
	}
	
	while(i<=mid){
		temp[k] = arr[i];
		k+=1;
		i+=1;
	}
	while(j<=end){
		temp[k] = arr[j];
		k+=1;
		j+=1;
	}

	for(i=start;i<=end;i++){
		arr[i] = temp[i-start];
	}
}

void mergeSort(int *arr, int start, int end){
	if(start<end){
		int mid = (start+end)/2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

int main(){

	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	mergeSort(arr, 0, n-1);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	return 0;
}