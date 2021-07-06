#include <bits/stdc++.h>
using namespace std;
 
 vector<int> equal(vector<int> &A){
 	unordered_map<int, vector<int>> map;
 	vector<int> V;
 	vector<int> res;
 	for(int i=0;i<A.size();i++){
 		for(int j=i+1;j<A.size();j++){
 			int key = A[i] + A[j];
 			if(map.find(key)!=map.end() && map[key][0]<i && map[key][1] != i && map[key][1] != j){
 				V.clear();
	 			V.push_back(map[key][0]);
	 			V.push_back(map[key][1]);
	 			V.push_back(i);
	 			V.push_back(j);
	 			if(res.empty()){res = V;}
	 			else{
	 				for(int i=0;i<4;i++){
	 					if(V[i]<res[i]){
	 						res = V;
	 						break;
	 					}
	 					else if (V[i]>res[i]) break;
	 				}
				}
 					
 			}
 			else{
 				map[key].push_back(i);
	 			map[key].push_back(j);
  			}
 		}
 		
 	}
 	return res;
 }


int main(){

	vector<int> A = { 0, 0, 1, 0, 2, 1 };
	vector<int> G = equal(A);
	for(int c : G){
		cout<<c;
	}

	return 0;
}