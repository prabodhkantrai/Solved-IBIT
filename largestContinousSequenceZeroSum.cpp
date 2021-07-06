#include <bits/stdc++.h>
using namespace std;
int maxCount;

/*void helper(vector<int> &A, vector<int> &V, vector<int> &res, int s, int sum){
	if(sum==0 && V.size()>0){
		if(V.size()>maxCount){
			maxCount = V.size();
			res = V;
		}
	}

	for(int i=s;i<A.size();i++){
		V.push_back(A[i]);
		helper(A,V,res,i+1, sum + A[i]);
		V.pop_back();
	}
	return;
}*/

vector<int> lszero(vector<int> &A) {
	/*int i=0,j=0, count=1, sum=A[0], maxcount = 0;
	int x,y;
	sort(A.begin, A.end);
	while(j<A.size()){
		j++;
		count++;
		sum+=A[j];
		while(sum<0 && i<=j){
			sum-=A[i];
			i++;
			count--;
		}

		if(sum==0 && count>maxcount){
			maxcount = count;
			x=i;
			y=j;
		}
	}	
	vector<int> V;
	for(i=x;i<=y;i++){
		V.push_back(A[i]);
	}
	return V;*/

	//Recursion Body//

	/*maxCount=0;
	int sum=0;
	vector<int> V;
	vector<int> res;
	helper(A, V, res, 0, sum);
	return res;*/

	int sum = 0, maxC = 0, x=0, y=0;
	vector<int> V;
	unordered_map<int, int> mymap;
	mymap[0] = -1;
	for(int i=0;i<A.size();i++){
		sum+=A[i];
		if(mymap.find(sum)!=mymap.end()){
			if(i - mymap[sum]>maxC){
				maxC = i - mymap[sum];
				x = mymap[sum];
				y = i;
			}
		}
		else mymap[sum] = i;
	}

	for(int i=x+1;i<=y;i++){
		V.push_back(A[i]);
	}
	return V;


}

 
int main(){
	vector<int> A = {1, 2, -3, 3 };
	vector<int> G = lszero(A);
	for(int i=0;i<G.size();i++){
		cout<<G[i]<<" ";
	}
	return 0;
}