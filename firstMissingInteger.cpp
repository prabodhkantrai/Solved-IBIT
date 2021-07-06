#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &A){
	/*int sum=0, min = 1, max=A[0];
	for(int i=0;i<A.size();i++){
		sum=sum+A[i];
		if(A[i]<min && A[i]>0)
			min=A[i];
		if(A[i]>max && A[i]>0){
			max=A[i];
		}
	}

	int actsum = 0;
	for(int i=0;i<=max;i++){
		actsum += i;
	}
	if(actsum==sum && max>=0)
		return max+1;
	
	else
		return actsum - sum;*/

	/*
	sort(A.begin(), A.end());
	int min = A[0];
	int max = A[A.size()-1];
	for(int i=0;i<A.size();i++){
		if(A[i] != min && A[i]>0 && min>0){
			num = min;
			break;
		}
		min++;
		if (min==0) min++;
	}
	if(max>0 && num==1){
		return max+1;
	} 
	else
		return num;*/
	
	int q=1;
	sort(A.begin(), A.end());
	int i=0;
	int num=1;
	while(i!=A.size()){
		if(A[i]>0){
			if(A[i]!=q){
				num = q;
				break;
			}
			q++;
		}
		i++;
	}
	if(i==A.size() && A[A.size()-1]>0){
		return A[A.size()-1]+1;
	}
	else if(A[A.size()-1]<0){
		return 1;
	}
	else
		return num;
}

int main(){
	int x,n;
	cin>>x;
	vector <int> A;
	for(int i=0;i<x;i++){
		cin>>n;
		A.push_back(n);
	}

	cout<<firstMissingPositive(A);

	return 0;
}